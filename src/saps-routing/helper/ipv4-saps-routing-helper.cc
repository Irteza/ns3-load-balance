/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

#include "ipv4-saps-routing-helper.h"
#include "ns3/log.h"

namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("Ipv4SapsRoutingHelper");

Ipv4SapsRoutingHelper::Ipv4SapsRoutingHelper ()
{

}

Ipv4SapsRoutingHelper::Ipv4SapsRoutingHelper (const Ipv4SapsRoutingHelper&)
{

}
  
Ipv4SapsRoutingHelper*
Ipv4SapsRoutingHelper::Copy (void) const
{
  return new Ipv4SapsRoutingHelper (*this);
}

Ptr<Ipv4RoutingProtocol>
Ipv4SapsRoutingHelper::Create (Ptr<Node> node) const
{
  Ptr<Ipv4SapsRouting> SapsRouting = CreateObject<Ipv4SapsRouting> ();
  return SapsRouting;
}

Ptr<Ipv4SapsRouting>
Ipv4SapsRoutingHelper::GetSapsRouting (Ptr<Ipv4> ipv4) const
{
  Ptr<Ipv4RoutingProtocol> ipv4rp = ipv4->GetRoutingProtocol ();
  if (DynamicCast<Ipv4SapsRouting> (ipv4rp))
  {
    return DynamicCast<Ipv4SapsRouting> (ipv4rp);
  }
  if (DynamicCast<Ipv4ListRouting> (ipv4rp))
  {
    Ptr<Ipv4ListRouting> lrp = DynamicCast<Ipv4ListRouting> (ipv4rp);
    int16_t priority;
    for (uint32_t i = 0; i < lrp->GetNRoutingProtocols ();  i++)
    {
      Ptr<Ipv4RoutingProtocol> temp = lrp->GetRoutingProtocol (i, priority);
      if (DynamicCast<Ipv4SapsRouting> (temp))
      {
        return DynamicCast<Ipv4SapsRouting> (temp);
      }
    }
  }

  return 0;
}

}

