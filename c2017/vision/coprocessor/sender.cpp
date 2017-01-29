#include "sender.h"

namespace c2017 {
namespace vision {

void RunSender() {
  aos::vision::TXUdpSocket sender_socket("10.86.78.20", 1678);
  auto queue_reader = vision_queue.MakeReader();
  void* buffer = malloc(1024);
  while(true) {
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    auto message = queue_reader.ReadLastMessage();
    if (message) {
      message.value()->SerializeToArray(buffer, 1024);
    }
    sender_socket.Send(buffer, 1024);
  }
}

muan::vision::VisionPositionQueue vision_queue;

}
}
