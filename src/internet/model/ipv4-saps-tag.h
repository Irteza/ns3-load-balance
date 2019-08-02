#ifndef NS3_IPV4_SAPS_TAG
#define NS3_IPV4_SAPS_TAG

#include "ns3/tag.h"
#include "ns3/ipv4-address.h"

namespace ns3 {

class Ipv4SapsTag : public Tag
{
public:
  Ipv4SapsTag ();

  void SetOriginalDestAddr (Ipv4Address addr);

  Ipv4Address GetOriginalDestAddr (void) const;

  static TypeId GetTypeId (void);

  virtual TypeId GetInstanceTypeId (void) const;

  virtual uint32_t GetSerializedSize (void) const;

  virtual void Serialize (TagBuffer i) const;

  virtual void Deserialize (TagBuffer i);

  virtual void Print (std::ostream &os) const;

private:
  Ipv4Address m_addr;
};

}

#endif
