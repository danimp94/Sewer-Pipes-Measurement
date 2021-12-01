#include <PointCloud.h>
#include <RansacShapeDetector.h>
#include <CylinderPrimitiveShapeConstructor.h>

#include <algorithm>
#include <string>
#include <fstream>
#include <vector>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream
#include <iostream>

#include "happly.h"

// From https://stackoverflow.com/questions/865668/parsing-command-line-arguments-in-c

class InputParser{
    public:
        InputParser (int &argc, char **argv){
            for (int i=1; i < argc; ++i)
                this->tokens.push_back(std::string(argv[i]));
        }
        /// @author iain
        const std::string& getCmdOption(const std::string &option) const{
            std::vector<std::string>::const_iterator itr;
            itr =  std::find(this->tokens.begin(), this->tokens.end(), option);
            if (itr != this->tokens.end() && ++itr != this->tokens.end()){
                return *itr;
            }
            static const std::string empty_string("");
            return empty_string;
        }
        /// @author iain
        bool cmdOptionExists(const std::string &option) const{
            return std::find(this->tokens.begin(), this->tokens.end(), option)
                   != this->tokens.end();
        }
    private:
        std::vector <std::string> tokens;
};



int main(int argc, char **argv)
{
    InputParser input(argc, argv);
    
    const std::string &filename = input.getCmdOption("-f");
    
    if (filename.empty()){
        return 0;
    }
    
    happly::PLYData plyIn(filename);
    
    std::vector<std::array<double, 3>> vPos = plyIn.getVertexPositions();

    PointCloud pc;

    // Transfer points to the new array. Only iterate through x, y, z coords
    int index = 0;

    for (const auto& pointCoord : vPos) {
        // Iterate through X coords and chec if corresponding y, z coords are present
        
        Vec3f pos(pointCoord[0],
            pointCoord[1],
            pointCoord[2]);

        Point p(pos);
        pc.push_back(p);
        }

        index++;
    }

    Vec3f checkMax(-500, -500, -500);
    Vec3f checkMin(500, 500, 500);
    

    // Loop through these points to get min/max
    for (const auto& point : pc) {
        if (point[0] < checkMin[0]) {
            checkMin[0] = point[0];
        }
        else if (point[0] > checkMax[0]) {
            checkMax[0] = point[0];
        }

        if (point[1] < checkMin[1]) {
            checkMin[1] = point[1];
        }
        else if (point[1] > checkMax[1]) {
            checkMax[1] = point[1];
        }

        if (point[2] < checkMin[2]) {
            checkMin[2] = point[2];
        }
        else if (point[2] > checkMax[2]) {
            checkMax[2] = point[2];
        }

    }
    
    pc.setBBox(checkMin, checkMax);
    

	// fill or load point cloud from file
	// ...
	// don't forget to set the bbox in pc
    float scale = pc.getScale();
    pc.calcNormals(.01f * scale);


	RansacShapeDetector::Options ransacOptions;
	ransacOptions.m_epsilon = 0.007; // set distance threshold to .01f of bounding box width
		// NOTE: Internally the distance threshold is taken as 3 * ransacOptions.m_epsilon!!!
	ransacOptions.m_bitmapEpsilon = .02 * pc.getScale(); // set bitmap resolution to .02f of bounding box width
		// NOTE: This threshold is NOT multiplied internally!
	ransacOptions.m_normalThresh = 0.9f; // this is the cos of the maximal normal deviation
	ransacOptions.m_minSupport = 500; // this is the minimal numer of points required for a primitive
	ransacOptions.m_probability = .01f; // this is the "probability" with which a primitive is overlooked
    ransacOptions.m_fitting = RansacShapeDetector::Options::LS_FITTING;

	RansacShapeDetector detector(ransacOptions); // the detector object

	// set which primitives are to be detected by adding the respective constructors
    detector.Add(new CylinderPrimitiveShapeConstructor());

	MiscLib::Vector< std::pair< MiscLib::RefCountPtr< PrimitiveShape >, size_t > > shapes; // stores the detected shapes
	size_t remaining = detector.Detect(pc, 0, pc.size(), &shapes); // run detection
		// returns number of unassigned points
		// the array shapes is filled with pointers to the detected shapes
		// the second element per shapes gives the number of points assigned to that primitive (the support)
		// the points belonging to the first shape (shapes[0]) have been sorted to the end of pc,
		// i.e. into the range [ pc.size() - shapes[0].second, pc.size() )
		// the points of shape i are found in the range
		// [ pc.size() - \sum_{j=0..i} shapes[j].second, pc.size() - \sum_{j=0..i-1} shapes[j].second )

    auto outputFilePath = filename + "-cylinders.txt";

    std::filebuf fb;
    fb.open(outputFilePath, std::ios::out);
    std::ostream os(&fb);
    os << "Support Height AngDir[0] AngDir[1] AngDir[2] YDir[0] YDir[1] YDir[2] Identifier axisDir[0] axisDir[1] axisDir[2] axisPos[0], axisPos[1] axisPos[2] radius angularRotatedRadians" << std::endl;
    

    for (const auto& shape : shapes) {
        if (shape.first->Identifier() == 2) { // 2 equals "Cylinder" type
		
            os << shape.second << " " << cyl->Height() << " " << angDir[0] << " " << angDir[1] << " " << angDir[2]; // Write support for the cylinder
            os << " " << Y[0] << " " << Y[1] << " " << Y[2] << " ";
            shape.first->Serialize(&os, false);

        }
    }

}