/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#ifndef IPV4_SAPS_ROUTING_HELPER_H
#define IPV4_SAPS_ROUTING_HELPER_H

#include "ns3/ipv4-saps-routing.h"
#include "ns3/ipv4-routing-helper.h"

namespace ns3 {

class Ipv4SapsRoutingHelper : public Ipv4RoutingHelper
{
public:
    Ipv4SapsRoutingHelper ();
    Ipv4SapsRoutingHelper (const Ipv4SapsRoutingHelper&);

    Ipv4SapsRoutingHelper *Copy (void) const;

    virtual Ptr<Ipv4RoutingProtocol> Create (Ptr<Node> node) const;

    Ptr<Ipv4SapsRouting> GetSapsRouting (Ptr<Ipv4> ipv4) const;
};

}

#endif /* IPV4_SAPS_ROUTING_HELPER_H */

