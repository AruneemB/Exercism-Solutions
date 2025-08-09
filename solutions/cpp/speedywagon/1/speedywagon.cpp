#include "speedywagon.h"

namespace speedywagon {

// Enter your code below:
bool connection_check(pillar_men_sensor* sensor) 
    {
		return (sensor != nullptr);
	}
    
int activity_counter(const pillar_men_sensor* sensors, size_t dimension) 
    {
        int total_activity{0};
        
        for (size_t i{0}; i < dimension; ++i) 
        {
            total_activity += sensors[i].activity;
        }
        
        return total_activity;
    }

bool alarm_control(pillar_men_sensor* sensor) 
    {
		return connection_check(sensor) && activity_counter(sensor, 1) > 0;
	}

bool uv_alarm(pillar_men_sensor* sensor) 
    {
		if (!connection_check(sensor))
        {
            return false;
        }

		int heuristic = uv_light_heuristic(&sensor->data);

		if (heuristic > sensor->activity)
        {
            return true;
        }
        else
        {
            return false;
        }
	}
    
// Please don't change the interface of the uv_light_heuristic function
int uv_light_heuristic(std::vector<int>* data_array) {
    double avg{};
    for (auto element : *data_array) {
        avg += element;
    }
    avg /= data_array->size();
    int uv_index{};
    for (auto element : *data_array) {
        if (element > avg) ++uv_index;
    }
    return uv_index;
}

}  // namespace speedywagon