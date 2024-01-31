# soda-sim-proto-v1

The soda-sim-proto-v1 includes implementation of the generic snesors messages for the SodaSim.

## Sensors message serialization / deserialization 
* _camera.hpp_ - generic cameras message (sends via ZMQ)
* _lidar.hpp_ - generic LiDAR message (sends via UDP)
* _radar.hpp_ - generic radar message (sends via UDP)
* _ultrasonic.hpp_ - generic ultrasonic message (sends via UDP)
* _vehicleState.hpp_ - generic vehicle state message (sends via UDP)

## Usage example (for Lidar.hpp, Radar.hpp, Ultrasonic.hpp)

Serialization example:  
```cpp
std::stringstream stream_out(std::ios_base::out | std::ios_base::binary); 
int points_count = soda::write(sout, Scan);
if (!stream_out)
{
    std::cout << "Serialization error";
    return;
}
const uint8* data = (const uint8*)stream_out.str().data();
size_t size = stream_out.str().length();
```


Deserialization example:  
```cpp
std::istringstream stream_in(std::string(data, size));
soda::read(stream_in, Scan);
if (!stream_in ) 
{
    std::cout << "Deserialization error" << std::endl;
    return;
}
```

## Contact
Please feel free to provide feedback or ask questions by creating a Github issue. For inquiries about collaboration, please email us at sim@soda.auto.

## Copyright and License
Copyright © 2023 SODA.AUTO UK LTD. ALL RIGHTS RESERVED.  
This software contains code licensed as described in [LICENSE](https://github.com/soda-auto/SodaSim/blob/master/LICENSE.md).  
