#ifndef C2017_VISION_ROBOT_VISION_H_
#define C2017_VISION_ROBOT_VISION_H_

#include "c2017/queue_manager/queue_manager.h"
#include "c2017/subsystems/drivetrain/drivetrain_base.h"
#include "c2017/vision/queue_types.h"
#include "muan/actions/drivetrain_action.h"

namespace c2017 {
namespace vision {

class VisionSubsystem {
 public:
  VisionSubsystem();
  void SetGoal(VisionGoalProto goal);
  void Update();

 protected:
  bool running_;
  bool should_align_;
  muan::actions::DrivetrainProperties properties_;
  VisionInputQueue::QueueReader vision_input_reader_;
  muan::wpilib::DriverStationQueue::QueueReader driverstation_reader_;
  muan::actions::DrivetrainAction action_;
};

}  // namespace vision
}  // namespace c2017

#endif  // C2017_VISION_ROBOT_VISION_H_
