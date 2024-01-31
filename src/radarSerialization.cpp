#include "soda/sim/proto-v1/radar.hpp"
#include <limits>
#include <cassert>

namespace soda
{
namespace sim
{
namespace proto_v1 
{

int write(std::ostream & out, RadarScan const& rscan) 
{
    write(out, &rscan.device_id, sizeof(rscan.device_id));
    if (! out) return -1;

    write(out, &rscan.device_timestamp, sizeof(rscan.device_timestamp));
    if (! out) return -1;

    std::uint16_t const items_count = static_cast<decltype(items_count)>(rscan.items.size());
    assert(rscan.items.size() <= std::numeric_limits<decltype(items_count)>::max());
    write(out, &items_count, sizeof(items_count));
    if (! out) return -1;

    if (items_count == 0) return items_count;

    write(out, rscan.items.data(), rscan.items.size() * sizeof(RadarCluster));
    if (! out) return -1;

    return items_count;
}

void read(std::istream & in, RadarScan & rscan) 
{
    read(in, &rscan.device_id, sizeof(rscan.device_id));
    if (! in) return;

    read(in, &rscan.device_timestamp, sizeof(rscan.device_timestamp));
    if (! in) return;

    std::uint16_t items_count;
    read(in, &items_count, sizeof(items_count));
    if (! in) return;

    rscan.items.resize(items_count);
    read(in, rscan.items.data(), rscan.items.size() * sizeof(RadarCluster));
    if (! in) return;
}

} // namespace sim
} // namespace proto_v1
} // namespace soda
