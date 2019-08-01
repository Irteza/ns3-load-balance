#include "ipv4-saps-helper.h"
#include "ns3/tcp-l4-protocol.h"
#include "ns3/ipv4-routing-protocol.h"
#include "ns3/ipv4-list-routing.h"

namespace ns3 {

Ipv4SapsHelper::Ipv4SapsHelper ()
{

}

Ipv4SapsHelper::~Ipv4SapsHelper ()
{

}

Ipv4SapsHelper*
Ipv4SapsHelper::Copy (void) const
{
  return new Ipv4SapsHelper (*this);
}

Ptr<Ipv4Saps>
Ipv4SapsHelper::Create (Ptr<Node> node) const
{
  return CreateObject<Ipv4Saps> ();
}

Ptr<Ipv4Saps>
Ipv4SapsHelper::GetIpv4Saps (Ptr<Ipv4> ipv4) const
{
  Ptr<Ipv4RoutingProtocol> ipv4rp = ipv4->GetRoutingProtocol ();
  if (DynamicCast<Ipv4ListRouting>(ipv4rp))
  {
    return (DynamicCast<Ipv4ListRouting>(ipv4rp))->GetSaps();
  }
  return 0;
}

}
