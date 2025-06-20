/****************************************************************

  Generated by Eclipse Cyclone DDS IDL to CXX Translator
  File name: UwbSwitch_.idl
  Source: UwbSwitch_.hpp
  Cyclone DDS: v0.10.2

*****************************************************************/
#ifndef DDSCXX_UNITREE_IDL_GO2_UWBSWITCH__HPP
#define DDSCXX_UNITREE_IDL_GO2_UWBSWITCH__HPP

#include <cstdint>

namespace unitree_go
{
namespace msg
{
namespace dds_
{
class UwbSwitch_
{
private:
 uint8_t enabled_ = 0;

public:
  UwbSwitch_() = default;

  explicit UwbSwitch_(
    uint8_t enabled) :
    enabled_(enabled) { }

  uint8_t enabled() const { return this->enabled_; }
  uint8_t& enabled() { return this->enabled_; }
  void enabled(uint8_t _val_) { this->enabled_ = _val_; }

  bool operator==(const UwbSwitch_& _other) const
  {
    (void) _other;
    return enabled_ == _other.enabled_;
  }

  bool operator!=(const UwbSwitch_& _other) const
  {
    return !(*this == _other);
  }

};

}

}

}

#include "dds/topic/TopicTraits.hpp"
#include "org/eclipse/cyclonedds/topic/datatopic.hpp"

namespace org {
namespace eclipse {
namespace cyclonedds {
namespace topic {

template <> constexpr const char* TopicTraits<::unitree_go::msg::dds_::UwbSwitch_>::getTypeName()
{
  return "unitree_go::msg::dds_::UwbSwitch_";
}

template <> constexpr bool TopicTraits<::unitree_go::msg::dds_::UwbSwitch_>::isKeyless()
{
  return true;
}

#ifdef DDSCXX_HAS_TYPE_DISCOVERY
template<> constexpr unsigned int TopicTraits<::unitree_go::msg::dds_::UwbSwitch_>::type_map_blob_sz() { return 218; }
template<> constexpr unsigned int TopicTraits<::unitree_go::msg::dds_::UwbSwitch_>::type_info_blob_sz() { return 100; }
template<> inline const uint8_t * TopicTraits<::unitree_go::msg::dds_::UwbSwitch_>::type_map_blob() {
  static const uint8_t blob[] = {
 0x3b,  0x00,  0x00,  0x00,  0x01,  0x00,  0x00,  0x00,  0xf1,  0xb3,  0xcf,  0xfe,  0xd4,  0x3a,  0x87,  0x3e,
 0x4b,  0xff,  0x03,  0x70,  0x95,  0x52,  0x60,  0x00,  0x23,  0x00,  0x00,  0x00,  0xf1,  0x51,  0x01,  0x00,
 0x01,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x13,  0x00,  0x00,  0x00,  0x01,  0x00,  0x00,  0x00,
 0x0b,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x01,  0x00,  0x02,  0xa1,  0x03,  0x11,  0x45,  0x00,
 0x6e,  0x00,  0x00,  0x00,  0x01,  0x00,  0x00,  0x00,  0xf2,  0x22,  0x0e,  0x76,  0xfa,  0x1b,  0x1c,  0x22,
 0x03,  0x2c,  0x71,  0xd3,  0x7c,  0x77,  0x05,  0x00,  0x56,  0x00,  0x00,  0x00,  0xf2,  0x51,  0x01,  0x00,
 0x2a,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x22,  0x00,  0x00,  0x00,  0x75,  0x6e,  0x69,  0x74,
 0x72,  0x65,  0x65,  0x5f,  0x67,  0x6f,  0x3a,  0x3a,  0x6d,  0x73,  0x67,  0x3a,  0x3a,  0x64,  0x64,  0x73,
 0x5f,  0x3a,  0x3a,  0x55,  0x77,  0x62,  0x53,  0x77,  0x69,  0x74,  0x63,  0x68,  0x5f,  0x00,  0x00,  0x00,
 0x1e,  0x00,  0x00,  0x00,  0x01,  0x00,  0x00,  0x00,  0x16,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
 0x01,  0x00,  0x02,  0x00,  0x08,  0x00,  0x00,  0x00,  0x65,  0x6e,  0x61,  0x62,  0x6c,  0x65,  0x64,  0x00,
 0x00,  0x00,  0x00,  0x00,  0x22,  0x00,  0x00,  0x00,  0x01,  0x00,  0x00,  0x00,  0xf2,  0x22,  0x0e,  0x76,
 0xfa,  0x1b,  0x1c,  0x22,  0x03,  0x2c,  0x71,  0xd3,  0x7c,  0x77,  0x05,  0xf1,  0xb3,  0xcf,  0xfe,  0xd4,
 0x3a,  0x87,  0x3e,  0x4b,  0xff,  0x03,  0x70,  0x95,  0x52,  0x60, };
  return blob;
}
template<> inline const uint8_t * TopicTraits<::unitree_go::msg::dds_::UwbSwitch_>::type_info_blob() {
  static const uint8_t blob[] = {
 0x60,  0x00,  0x00,  0x00,  0x01,  0x10,  0x00,  0x40,  0x28,  0x00,  0x00,  0x00,  0x24,  0x00,  0x00,  0x00,
 0x14,  0x00,  0x00,  0x00,  0xf1,  0xb3,  0xcf,  0xfe,  0xd4,  0x3a,  0x87,  0x3e,  0x4b,  0xff,  0x03,  0x70,
 0x95,  0x52,  0x60,  0x00,  0x27,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x04,  0x00,  0x00,  0x00,
 0x00,  0x00,  0x00,  0x00,  0x02,  0x10,  0x00,  0x40,  0x28,  0x00,  0x00,  0x00,  0x24,  0x00,  0x00,  0x00,
 0x14,  0x00,  0x00,  0x00,  0xf2,  0x22,  0x0e,  0x76,  0xfa,  0x1b,  0x1c,  0x22,  0x03,  0x2c,  0x71,  0xd3,
 0x7c,  0x77,  0x05,  0x00,  0x5a,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x04,  0x00,  0x00,  0x00,
 0x00,  0x00,  0x00,  0x00, };
  return blob;
}
#endif //DDSCXX_HAS_TYPE_DISCOVERY

} //namespace topic
} //namespace cyclonedds
} //namespace eclipse
} //namespace org

namespace dds {
namespace topic {

template <>
struct topic_type_name<::unitree_go::msg::dds_::UwbSwitch_>
{
    static std::string value()
    {
      return org::eclipse::cyclonedds::topic::TopicTraits<::unitree_go::msg::dds_::UwbSwitch_>::getTypeName();
    }
};

}
}

REGISTER_TOPIC_TYPE(::unitree_go::msg::dds_::UwbSwitch_)

namespace org{
namespace eclipse{
namespace cyclonedds{
namespace core{
namespace cdr{

template<>
propvec &get_type_props<::unitree_go::msg::dds_::UwbSwitch_>();

template<typename T, std::enable_if_t<std::is_base_of<cdr_stream, T>::value, bool> = true >
bool write(T& streamer, const ::unitree_go::msg::dds_::UwbSwitch_& instance, entity_properties_t *props) {
  (void)instance;
  if (!streamer.start_struct(*props))
    return false;
  auto prop = streamer.first_entity(props);
  while (prop) {
    switch (prop->m_id) {
      case 0:
      if (!streamer.start_member(*prop))
        return false;
      if (!write(streamer, instance.enabled()))
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
    }
    prop = streamer.next_entity(prop);
  }
  return streamer.finish_struct(*props);
}

template<typename S, std::enable_if_t<std::is_base_of<cdr_stream, S>::value, bool> = true >
bool write(S& str, const ::unitree_go::msg::dds_::UwbSwitch_& instance, bool as_key) {
  auto &props = get_type_props<::unitree_go::msg::dds_::UwbSwitch_>();
  str.set_mode(cdr_stream::stream_mode::write, as_key);
  return write(str, instance, props.data());
}

template<typename T, std::enable_if_t<std::is_base_of<cdr_stream, T>::value, bool> = true >
bool read(T& streamer, ::unitree_go::msg::dds_::UwbSwitch_& instance, entity_properties_t *props) {
  (void)instance;
  if (!streamer.start_struct(*props))
    return false;
  auto prop = streamer.first_entity(props);
  while (prop) {
    switch (prop->m_id) {
      case 0:
      if (!streamer.start_member(*prop))
        return false;
      if (!read(streamer, instance.enabled()))
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
    }
    prop = streamer.next_entity(prop);
  }
  return streamer.finish_struct(*props);
}

template<typename S, std::enable_if_t<std::is_base_of<cdr_stream, S>::value, bool> = true >
bool read(S& str, ::unitree_go::msg::dds_::UwbSwitch_& instance, bool as_key) {
  auto &props = get_type_props<::unitree_go::msg::dds_::UwbSwitch_>();
  str.set_mode(cdr_stream::stream_mode::read, as_key);
  return read(str, instance, props.data());
}

template<typename T, std::enable_if_t<std::is_base_of<cdr_stream, T>::value, bool> = true >
bool move(T& streamer, const ::unitree_go::msg::dds_::UwbSwitch_& instance, entity_properties_t *props) {
  (void)instance;
  if (!streamer.start_struct(*props))
    return false;
  auto prop = streamer.first_entity(props);
  while (prop) {
    switch (prop->m_id) {
      case 0:
      if (!streamer.start_member(*prop))
        return false;
      if (!move(streamer, instance.enabled()))
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
    }
    prop = streamer.next_entity(prop);
  }
  return streamer.finish_struct(*props);
}

template<typename S, std::enable_if_t<std::is_base_of<cdr_stream, S>::value, bool> = true >
bool move(S& str, const ::unitree_go::msg::dds_::UwbSwitch_& instance, bool as_key) {
  auto &props = get_type_props<::unitree_go::msg::dds_::UwbSwitch_>();
  str.set_mode(cdr_stream::stream_mode::move, as_key);
  return move(str, instance, props.data());
}

template<typename T, std::enable_if_t<std::is_base_of<cdr_stream, T>::value, bool> = true >
bool max(T& streamer, const ::unitree_go::msg::dds_::UwbSwitch_& instance, entity_properties_t *props) {
  (void)instance;
  if (!streamer.start_struct(*props))
    return false;
  auto prop = streamer.first_entity(props);
  while (prop) {
    switch (prop->m_id) {
      case 0:
      if (!streamer.start_member(*prop))
        return false;
      if (!max(streamer, instance.enabled()))
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
    }
    prop = streamer.next_entity(prop);
  }
  return streamer.finish_struct(*props);
}

template<typename S, std::enable_if_t<std::is_base_of<cdr_stream, S>::value, bool> = true >
bool max(S& str, const ::unitree_go::msg::dds_::UwbSwitch_& instance, bool as_key) {
  auto &props = get_type_props<::unitree_go::msg::dds_::UwbSwitch_>();
  str.set_mode(cdr_stream::stream_mode::max, as_key);
  return max(str, instance, props.data());
}

} //namespace cdr
} //namespace core
} //namespace cyclonedds
} //namespace eclipse
} //namespace org

#endif // DDSCXX_UNITREE_IDL_GO2_UWBSWITCH__HPP
