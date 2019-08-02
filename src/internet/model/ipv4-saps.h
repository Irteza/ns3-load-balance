#ifndef IPV4_SAPS_H
#define IPV4_SAPS_H

#include <map>
#include <vector>
#include "ns3/object.h"
#include "ns3/ipv4-address.h"

namespace ns3 {

class Ipv4Saps : public Object
{

public:
  static TypeId GetTypeId (void);

  Ipv4Saps ();
  ~Ipv4Saps ();

  Ipv4Address GetCoreSwitchAddress (uint32_t flowId);

  void AddCoreSwitchAddress (Ipv4Address address);
  void AddCoreSwitchAddress (uint32_t k, Ipv4Address address);

private:
  std::vector<Ipv4Address> m_coreSwitchAddressList;
  std::map<uint32_t, uint32_t> m_indexMap;
};

}

#endif
