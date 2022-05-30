#include "consumer.h"
#include "substrait/plan.pb.h"
#include <google/protobuf/util/json_util.h>
#include <iostream>

bool consume(const std::string &message) {
    substrait::Plan plan;
    if (!plan.ParseFromString(message)) {
        return false;
    }
    std::string output;
    google::protobuf::util::MessageToJsonString(plan, &output);
    std::cout << output << std::endl;
    return true;
}
