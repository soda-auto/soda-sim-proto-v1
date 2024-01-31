#include "soda/sim/proto-v1/lidar.hpp"
#include <cassert>
#include <limits>

namespace soda
{
namespace sim
{
namespace proto_v1 
{

int write(std::ostream& out, LidarScan const& scan)
{    
    write(out, &scan.device_id, sizeof(scan.device_id));
    if (! out) return -1;

    write(out, &scan.device_timestamp, sizeof(scan.device_timestamp));
    if (! out) return -1;

    write(out, &scan.scan_id, sizeof(scan.scan_id));
    if (! out) return -1;

    write(out, &scan.block_count, sizeof(scan.block_count));
    if (! out) return -1;

    write(out, &scan.block_id, sizeof(scan.block_id));
    if (! out) return -1;

    std::uint16_t const points_count =
    static_cast<decltype(points_count)>(scan.points.size());
    assert(
    scan.points.size() <= std::numeric_limits<decltype(points_count)>::max());
    write(out, &points_count, sizeof(points_count));
    if (! out) return -1;

    if (points_count == 0) return points_count;

    write(out, scan.points.data(), scan.points.size() * sizeof(LidarScanPoint));
    if (! out) return -1;

    return points_count;
}

void read(std::istream& in, LidarScan& scan)
{    
    read(in, &scan.device_id, sizeof(scan.device_id));
    if (! in) return;

    read(in, &scan.device_timestamp, sizeof(scan.device_timestamp));
    if (! in) return;

    read(in, &scan.scan_id, sizeof(scan.scan_id));
    if (! in) return;

    read(in, &scan.block_count, sizeof(scan.block_count));
    if (! in) return;

    read(in, &scan.block_id, sizeof(scan.block_id));
    if (! in) return;

    std::uint16_t points_count;
    read(in, &points_count, sizeof(points_count));
    if (! in) return;

    scan.points.resize(points_count);
    read(in, scan.points.data(), scan.points.size() * sizeof(LidarScanPoint));
    if (! in) return;
}

} // namespace sim
} // namespace proto_v1
} // namespace soda

