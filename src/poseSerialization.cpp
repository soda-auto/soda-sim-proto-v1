#include "soda/sim/proto-v1/pose.hpp"
#include <cassert>
#include <limits>

namespace soda
{
namespace sim
{
namespace proto_v1 
{

void write(std::ostream & out, Pose3d const& pose)
{
    std::uint8_t const type = pose.is2d() ? 0 : 1;
    write(out, &type, sizeof(type));
    if (! out) return;

    if (type == 0) 
    {
        auto value = pose.x();
        write(out, &value, sizeof(value));
        if (! out) return;

        value = pose.y();
        write(out, &value, sizeof(value));
        if (! out) return;

        value = pose.yaw();
        write(out, &value, sizeof(value));
        if (! out) return;
    }
    else if (type == 1) 
    {
        auto value = pose.x();
        write(out, &value, sizeof(value));
        if (! out) return;

        value = pose.y();
        write(out, &value, sizeof(value));
        if (! out) return;

        value = pose.z();
        write(out, &value, sizeof(value));
        if (! out) return;

        value = pose.roll();
        write(out, &value, sizeof(value));
        if (! out) return;

        value = pose.pitch();
        write(out, &value, sizeof(value));
        if (! out) return;

        value = pose.yaw();
        write(out, &value, sizeof(value));
        if (! out) return;
    }
    else 
    {
        assert(false);
    }
}

void read(std::istream & in, Pose3d & pose)
{
    std::uint8_t type;
    read(in, &type, sizeof(type));
    if (! in) return;

    if (type == 0) 
    {
        float value;

        read(in, &value, sizeof(value));
        if (! in) return;
        pose.setX(value);

        read(in, &value, sizeof(value));
        if (! in) return;
        pose.setY(value);

        read(in, &value, sizeof(value));
        if (! in) return;
        pose.setYaw(value);
    } 
    else if (type == 1) 
    {
        float value;

        read(in, &value, sizeof(value));
        if (! in) return;
        pose.setX(value);

        read(in, &value, sizeof(value));
        if (! in) return;
        pose.setY(value);

        read(in, &value, sizeof(value));
        if (! in) return;
        pose.setZ(value);

        read(in, &value, sizeof(value));
        if (! in) return;
        pose.setRoll(value);

        read(in, &value, sizeof(value));
        if (! in) return;
        pose.setPitch(value);

        read(in, &value, sizeof(value));
        if (! in) return;
        pose.setYaw(value);
    } 
    else 
    {
        assert(false);
    }
}

void write(std::ostream & out, Pose2d const& pose)
{
    std::uint8_t type = 0;
    write(out, &type, sizeof(type));
    if (! out) return;

    auto value = pose.x();
    write(out, &value, sizeof(value));
    if (! out) return;

    value = pose.y();
    write(out, &value, sizeof(value));
    if (! out) return;

    value = pose.yaw();
    write(out, &value, sizeof(value));
    if (! out) return;
}

void read(std::istream & in, Pose2d & pose)
{
    std::uint8_t type;
    read(in, &type, sizeof(type));
    if (! in) return;

    if (type == 0) 
    {
        float value;

        read(in, &value, sizeof(value));
        if (! in) return;
        pose.setX(value);

        read(in, &value, sizeof(value));
        if (! in) return;
        pose.setY(value);

        read(in, &value, sizeof(value));
        if (! in) return;
        pose.setYaw(value);
    }
    else 
    {
        assert(false);
    }
}

} // namespace sim
} // namespace proto_v1
} // namespace soda

