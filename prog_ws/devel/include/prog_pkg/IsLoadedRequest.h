// Generated by gencpp from file prog_pkg/IsLoadedRequest.msg
// DO NOT EDIT!


#ifndef PROG_PKG_MESSAGE_ISLOADEDREQUEST_H
#define PROG_PKG_MESSAGE_ISLOADEDREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace prog_pkg
{
template <class ContainerAllocator>
struct IsLoadedRequest_
{
  typedef IsLoadedRequest_<ContainerAllocator> Type;

  IsLoadedRequest_()
    {
    }
  IsLoadedRequest_(const ContainerAllocator& _alloc)
    {
  (void)_alloc;
    }







  typedef boost::shared_ptr< ::prog_pkg::IsLoadedRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::prog_pkg::IsLoadedRequest_<ContainerAllocator> const> ConstPtr;

}; // struct IsLoadedRequest_

typedef ::prog_pkg::IsLoadedRequest_<std::allocator<void> > IsLoadedRequest;

typedef boost::shared_ptr< ::prog_pkg::IsLoadedRequest > IsLoadedRequestPtr;
typedef boost::shared_ptr< ::prog_pkg::IsLoadedRequest const> IsLoadedRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::prog_pkg::IsLoadedRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::prog_pkg::IsLoadedRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


} // namespace prog_pkg

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::prog_pkg::IsLoadedRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::prog_pkg::IsLoadedRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::prog_pkg::IsLoadedRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::prog_pkg::IsLoadedRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::prog_pkg::IsLoadedRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::prog_pkg::IsLoadedRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::prog_pkg::IsLoadedRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::prog_pkg::IsLoadedRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::prog_pkg::IsLoadedRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "prog_pkg/IsLoadedRequest";
  }

  static const char* value(const ::prog_pkg::IsLoadedRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::prog_pkg::IsLoadedRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n"
;
  }

  static const char* value(const ::prog_pkg::IsLoadedRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::prog_pkg::IsLoadedRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct IsLoadedRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::prog_pkg::IsLoadedRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::prog_pkg::IsLoadedRequest_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace ros

#endif // PROG_PKG_MESSAGE_ISLOADEDREQUEST_H
