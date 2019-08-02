#include "ns3/log.h"
#include "ipv4-saps.h"

namespace ns3 {

NS_LOG_COMPONENT_DEFINE("Ipv4Saps");

NS_OBJECT_ENSURE_REGISTERED (Ipv4Saps);

TypeId
Ipv4Saps::GetTypeId (void)
{
  static TypeId tid = TypeId("ns3::Ipv4Saps")
      .SetParent<Object>()
      .SetGroupName ("Internet")
      .AddConstructor<Ipv4Saps> ();

  return tid;
}

Ipv4Saps::Ipv4Saps ()
{
  NS_LOG_FUNCTION (this);
}

Ipv4Saps::~Ipv4Saps ()
{
  NS_LOG_FUNCTION (this);
}

Ipv4Address
Ipv4Saps::GetCoreSwitchAddress (uint32_t flowId)
{
  NS_LOG_FUNCTION (this);

  uint32_t listSize = m_coreSwitchAddressList.size();

  if (listSize == 0)
  {
    return Ipv4Address ();
  }

  uint32_t index = rand () % listSize;

  std::map<uint32_t, uint32_t>::iterator itr = m_indexMap.find (flowId);

  if (itr != m_indexMap.end ())
  {
    index = itr->second;
  }
  m_indexMap[flowId] = ((index + 1) % listSize);

  Ipv4Address addr = m_coreSwitchAddressList[index];

  NS_LOG_DEBUG (this << " The index for flow: " << flowId << " is : " << index);
  return addr;
}

void
Ipv4Saps::AddCoreSwitchAddress (Ipv4Address addr)
{
  NS_LOG_FUNCTION (this << addr);
  m_coreSwitchAddressList.push_back (addr);
}

void
Ipv4Saps::AddCoreSwitchAddress (uint32_t k, Ipv4Address addr)
{
  for (uint32_t i = 0; i < k; i++)
  {
    Ipv4Saps::AddCoreSwitchAddress(addr);
  }
}

}
