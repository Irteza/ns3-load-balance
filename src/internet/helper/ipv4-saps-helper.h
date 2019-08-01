#ifndef IPV4_SAPS_HELPER
#define IPV4_SAPS_HELPER

#include "ns3/node.h"
#include "ns3/ipv4.h"
#include "ns3/ipv4-saps.h"

namespace ns3 {

class Ipv4SapsHelper
{
public:
  Ipv4SapsHelper ();
  virtual ~Ipv4SapsHelper ();

  Ipv4SapsHelper *Copy (void) const;
  virtual Ptr<Ipv4Saps> Create (Ptr<Node> node) const;
  Ptr<Ipv4Saps> GetIpv4Saps(Ptr<Ipv4> ipv4) const;
};

}

#endif
