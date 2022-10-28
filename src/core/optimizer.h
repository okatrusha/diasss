
#ifndef OPTIMIZER_H
#define OPTIMIZER_H

#include "frame.h"
#include "SSSpointfactor.h"
#include "LMtriangulatefactor.h"

#include <gtsam/base/Matrix.h>
#include <gtsam/geometry/Point3.h>
#include <gtsam/geometry/Pose3.h>

#include <gtsam/inference/Symbol.h>
#include <gtsam/slam/BetweenFactor.h>

#include <gtsam/nonlinear/ISAM2.h>
#include <gtsam/nonlinear/LevenbergMarquardtOptimizer.h>
#include <gtsam/nonlinear/NonlinearFactorGraph.h>
#include <gtsam/nonlinear/Values.h>


namespace Diasss
{

using namespace std;
using namespace cv;
using namespace gtsam;

    class Optimizer
    {

    public:

        // Trajectory optimization for a pair of side-scan waterfall images
        void static TrajOptimizationPair(Frame &SourceFrame, Frame &TargetFrame);

        std::vector<Vector6> static GetKpsPairs(const cv::Mat &kps, const int &id_s, const int &id_t,
                                         const std::vector<double> &alts_s, const std::vector<double> &gras_s,
                                         const std::vector<double> &alts_t, const std::vector<double> &gras_t);

        std::vector<Point3> static TriangulateLandmarks(const std::vector<Vector6> &kps_pairs, 
                                                        const std::vector<double> &tf_stb, const std::vector<double> &tf_port,
                                                        const int &img_id_s, const int &img_id_t,
                                                        const std::vector<cv::Mat> &geo_s, const std::vector<cv::Mat> &geo_t,
                                                        const std::vector<double> &alts_s, const std::vector<double> &alts_t,
                                                        const cv::Mat &dr_poses_s, const cv::Mat &dr_poses_t);

        

    };

}

#endif // OPTIMIZER_H