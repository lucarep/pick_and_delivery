// Generated by gencpp from file prog_pkg/Arrived.msg
// DO NOT EDIT!


#ifndef PROG_PKG_MESSAGE_ARRIVED_H
#define PROG_PKG_MESSAGE_ARRIVED_H


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
struct Arrived_
{
  typedef Arrived_<ContainerAllocator> Type;

  Arrived_()
    : reached_goal(0)  {
    }
  Arrived_(const ContainerAllocator& _alloc)
    : reached_goal(0)  {
  (void)_alloc;
    }



   typedef int64_t _reached_goal_type;
  _reached_goal_type reached_goal;





  typedef boost::shared_ptr< ::prog_pkg::Arrived_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::prog_pkg::Arrived_<ContainerAllocator> const> ConstPtr;

}; // struct Arrived_

typedef ::prog_pkg::Arrived_<std::allocator<void> > Arrived;

typedef boost::shared_ptr< ::prog_pkg::Arrived > ArrivedPtr;
typedef boost::shared_ptr< ::prog_pkg::Arrived const> ArrivedConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::prog_pkg::Arrived_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::prog_pkg::Arrived_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::prog_pkg::Arrived_<ContainerAllocator1> & lhs, const ::prog_pkg::Arrived_<ContainerAllocator2> & rhs)
{
  return lhs.reached_goal == rhs.reached_goal;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::prog_pkg::Arrived_<ContainerAllocator1> & lhs, const ::prog_pkg::Arrived_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace prog_pkg

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::prog_pkg::Arrived_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::prog_pkg::Arrived_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::prog_pkg::Arrived_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::prog_pkg::Arrived_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::prog_pkg::Arrived_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::prog_pkg::Arrived_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::prog_pkg::Arrived_<ContainerAllocator> >
{
  static const char* value()
  {
    return "e06eb18f4448ce87af267960da61e43d";
  }

  static const char* value(const ::prog_pkg::Arrived_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xe06eb18f4448ce87ULL;
  static const uint64_t static_value2 = 0xaf267960da61e43dULL;
};

template<class ContainerAllocator>
struct DataType< ::prog_pkg::Arrived_<ContainerAllocator> >
{
  static const char* value()
  {
    return "prog_pkg/Arrived";
  }

  static const char* value(const ::prog_pkg::Arrived_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::prog_pkg::Arrived_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int64 reached_goal\n"
;
  }

  static const char* value(const ::prog_pkg::Arrived_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::prog_pkg::Arrived_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.reached_goal);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Arrived_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::prog_pkg::Arrived_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::prog_pkg::Arrived_<ContainerAllocator>& v)
  {
    s << indent << "reached_goal: ";
    Printer<int64_t>::stream(s, indent + "  ", v.reached_goal);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PROG_PKG_MESSAGE_ARRIVED_H
