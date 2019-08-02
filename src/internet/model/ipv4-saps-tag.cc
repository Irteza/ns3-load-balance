#include "ipv4-saps-tag.h"

namespace ns3
{

Ipv4SapsTag::Ipv4SapsTag () {}

void
Ipv4SapsTag::SetOriginalDestAddr (Ipv4Address addr)
{
  m_addr = addr;
}

Ipv4Address
Ipv4SapsTag::GetOriginalDestAddr (void) const
{
  return m_addr;
}

TypeId
Ipv4SapsTag::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::Ipv4SapsTag")
    .SetParent<Tag> ()
    .SetGroupName ("Internet")
    .AddConstructor<Ipv4SapsTag> ();
  return tid;
}

TypeId
Ipv4SapsTag::GetInstanceTypeId (void) const
{
  return GetTypeId ();
}

uint32_t
Ipv4SapsTag::GetSerializedSize (void) const
{
  return sizeof (uint32_t);
}

void
Ipv4SapsTag::Serialize (TagBuffer i) const
{
  i.WriteU32(m_addr.Get ());
}

void
Ipv4SapsTag::Deserialize (TagBuffer i)
{
  m_addr.Set (i.ReadU32 ());
}

void
Ipv4SapsTag::Print (std::ostream &os) const
{
  os << "IP_Saps_original_dest_addr = " << m_addr;
}
}
