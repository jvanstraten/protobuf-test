#include <iostream>
#include "consumer.h"
#include "producer.h"

int main(void) {
    if (!consume(produce())) {
        std::cerr << "Consumer failed" << std::endl;
    }
    return 0;
}
