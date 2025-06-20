/****************************************************************

  Generated by Eclipse Cyclone DDS IDL to CXX Translator
  File name: MainBoardState_.idl
  Source: MainBoardState_.hpp
  Cyclone DDS: v0.10.2

*****************************************************************/
#ifndef DDSCXX_UNITREE_IDL_HG_MAINBOARDSTATE__HPP
#define DDSCXX_UNITREE_IDL_HG_MAINBOARDSTATE__HPP

#include <cstdint>
#include <array>

namespace unitree_hg
{
namespace msg
{
namespace dds_
{
class MainBoardState_
{
private:
 std::array<uint16_t, 6> fan_state_ = { };
 std::array<int16_t, 6> temperature_ = { };
 std::array<float, 6> value_ = { };
 std::array<uint32_t, 6> state_ = { };

public:
  MainBoardState_() = default;

  explicit MainBoardState_(
    const std::array<uint16_t, 6>& fan_state,
    const std::array<int16_t, 6>& temperature,
    const std::array<float, 6>& value,
    const std::array<uint32_t, 6>& state) :
    fan_state_(fan_state),
    temperature_(temperature),
    value_(value),
    state_(state) { }

  const std::array<uint16_t, 6>& fan_state() const { return this->fan_state_; }
  std::array<uint16_t, 6>& fan_state() { return this->fan_state_; }
  void fan_state(const std::array<uint16_t, 6>& _val_) { this->fan_state_ = _val_; }
  void fan_state(std::array<uint16_t, 6>&& _val_) { this->fan_state_ = _val_; }
  const std::array<int16_t, 6>& temperature() const { return this->temperature_; }
  std::array<int16_t, 6>& temperature() { return this->temperature_; }
  void temperature(const std::array<int16_t, 6>& _val_) { this->temperature_ = _val_; }
  void temperature(std::array<int16_t, 6>&& _val_) { this->temperature_ = _val_; }
  const std::array<float, 6>& value() const { return this->value_; }
  std::array<float, 6>& value() { return this->value_; }
  void value(const std::array<float, 6>& _val_) { this->value_ = _val_; }
  void value(std::array<float, 6>&& _val_) { this->value_ = _val_; }
  const std::array<uint32_t, 6>& state() const { return this->state_; }
  std::array<uint32_t, 6>& state() { return this->state_; }
  void state(const std::array<uint32_t, 6>& _val_) { this->state_ = _val_; }
  void state(std::array<uint32_t, 6>&& _val_) { this->state_ = _val_; }

  bool operator==(const MainBoardState_& _other) const
  {
    (void) _other;
    return fan_state_ == _other.fan_state_ &&
      temperature_ == _other.temperature_ &&
      value_ == _other.value_ &&
      state_ == _other.state_;
  }

  bool operator!=(const MainBoardState_& _other) const
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

template <> constexpr const char* TopicTraits<::unitree_hg::msg::dds_::MainBoardState_>::getTypeName()
{
  return "unitree_hg::msg::dds_::MainBoardState_";
}

template <> constexpr bool TopicTraits<::unitree_hg::msg::dds_::MainBoardState_>::isKeyless()
{
  return true;
}

#ifdef DDSCXX_HAS_TYPE_DISCOVERY
template<> constexpr unsigned int TopicTraits<::unitree_hg::msg::dds_::MainBoardState_>::type_map_blob_sz() { return 446; }
template<> constexpr unsigned int TopicTraits<::unitree_hg::msg::dds_::MainBoardState_>::type_info_blob_sz() { return 100; }
template<> inline const uint8_t * TopicTraits<::unitree_hg::msg::dds_::MainBoardState_>::type_map_blob() {
  static const uint8_t blob[] = {
 0x9a,  0x00,  0x00,  0x00,  0x01,  0x00,  0x00,  0x00,  0xf1,  0xde,  0xab,  0xb8,  0xf4,  0x95,  0x16,  0x55,
 0x33,  0xd2,  0x9d,  0x46,  0x46,  0x5f,  0x6a,  0x00,  0x82,  0x00,  0x00,  0x00,  0xf1,  0x51,  0x01,  0x00,
 0x01,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x72,  0x00,  0x00,  0x00,  0x04,  0x00,  0x00,  0x00,
 0x16,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x01,  0x00,  0x90,  0xf3,  0x01,  0x00,  0x00,  0x00,
 0x01,  0x00,  0x00,  0x00,  0x06,  0x06,  0x6f,  0x80,  0x17,  0x1f,  0x00,  0x00,  0x16,  0x00,  0x00,  0x00,
 0x01,  0x00,  0x00,  0x00,  0x01,  0x00,  0x90,  0xf3,  0x01,  0x00,  0x00,  0x00,  0x01,  0x00,  0x00,  0x00,
 0x06,  0x03,  0xee,  0xf4,  0x38,  0xf7,  0x00,  0x00,  0x16,  0x00,  0x00,  0x00,  0x02,  0x00,  0x00,  0x00,
 0x01,  0x00,  0x90,  0xf3,  0x01,  0x00,  0x00,  0x00,  0x01,  0x00,  0x00,  0x00,  0x06,  0x09,  0x20,  0x63,
 0xc1,  0x60,  0x00,  0x00,  0x16,  0x00,  0x00,  0x00,  0x03,  0x00,  0x00,  0x00,  0x01,  0x00,  0x90,  0xf3,
 0x01,  0x00,  0x00,  0x00,  0x01,  0x00,  0x00,  0x00,  0x06,  0x07,  0x9e,  0xd3,  0x9e,  0x2e,  0x00,  0x00,
 0xf4,  0x00,  0x00,  0x00,  0x01,  0x00,  0x00,  0x00,  0xf2,  0x56,  0xc3,  0x59,  0xc8,  0xbe,  0x34,  0xec,
 0xd0,  0x38,  0xbc,  0x21,  0x76,  0x76,  0x4d,  0x00,  0xdc,  0x00,  0x00,  0x00,  0xf2,  0x51,  0x01,  0x00,
 0x2f,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x27,  0x00,  0x00,  0x00,  0x75,  0x6e,  0x69,  0x74,
 0x72,  0x65,  0x65,  0x5f,  0x68,  0x67,  0x3a,  0x3a,  0x6d,  0x73,  0x67,  0x3a,  0x3a,  0x64,  0x64,  0x73,
 0x5f,  0x3a,  0x3a,  0x4d,  0x61,  0x69,  0x6e,  0x42,  0x6f,  0x61,  0x72,  0x64,  0x53,  0x74,  0x61,  0x74,
 0x65,  0x5f,  0x00,  0x00,  0xa0,  0x00,  0x00,  0x00,  0x04,  0x00,  0x00,  0x00,  0x24,  0x00,  0x00,  0x00,
 0x00,  0x00,  0x00,  0x00,  0x01,  0x00,  0x90,  0xf3,  0x01,  0x00,  0x00,  0x00,  0x01,  0x00,  0x00,  0x00,
 0x06,  0x06,  0x00,  0x00,  0x0a,  0x00,  0x00,  0x00,  0x66,  0x61,  0x6e,  0x5f,  0x73,  0x74,  0x61,  0x74,
 0x65,  0x00,  0x00,  0x00,  0x26,  0x00,  0x00,  0x00,  0x01,  0x00,  0x00,  0x00,  0x01,  0x00,  0x90,  0xf3,
 0x01,  0x00,  0x00,  0x00,  0x01,  0x00,  0x00,  0x00,  0x06,  0x03,  0x00,  0x00,  0x0c,  0x00,  0x00,  0x00,
 0x74,  0x65,  0x6d,  0x70,  0x65,  0x72,  0x61,  0x74,  0x75,  0x72,  0x65,  0x00,  0x00,  0x00,  0x00,  0x00,
 0x20,  0x00,  0x00,  0x00,  0x02,  0x00,  0x00,  0x00,  0x01,  0x00,  0x90,  0xf3,  0x01,  0x00,  0x00,  0x00,
 0x01,  0x00,  0x00,  0x00,  0x06,  0x09,  0x00,  0x00,  0x06,  0x00,  0x00,  0x00,  0x76,  0x61,  0x6c,  0x75,
 0x65,  0x00,  0x00,  0x00,  0x20,  0x00,  0x00,  0x00,  0x03,  0x00,  0x00,  0x00,  0x01,  0x00,  0x90,  0xf3,
 0x01,  0x00,  0x00,  0x00,  0x01,  0x00,  0x00,  0x00,  0x06,  0x07,  0x00,  0x00,  0x06,  0x00,  0x00,  0x00,
 0x73,  0x74,  0x61,  0x74,  0x65,  0x00,  0x00,  0x00,  0x22,  0x00,  0x00,  0x00,  0x01,  0x00,  0x00,  0x00,
 0xf2,  0x56,  0xc3,  0x59,  0xc8,  0xbe,  0x34,  0xec,  0xd0,  0x38,  0xbc,  0x21,  0x76,  0x76,  0x4d,  0xf1,
 0xde,  0xab,  0xb8,  0xf4,  0x95,  0x16,  0x55,  0x33,  0xd2,  0x9d,  0x46,  0x46,  0x5f,  0x6a, };
  return blob;
}
template<> inline const uint8_t * TopicTraits<::unitree_hg::msg::dds_::MainBoardState_>::type_info_blob() {
  static const uint8_t blob[] = {
 0x60,  0x00,  0x00,  0x00,  0x01,  0x10,  0x00,  0x40,  0x28,  0x00,  0x00,  0x00,  0x24,  0x00,  0x00,  0x00,
 0x14,  0x00,  0x00,  0x00,  0xf1,  0xde,  0xab,  0xb8,  0xf4,  0x95,  0x16,  0x55,  0x33,  0xd2,  0x9d,  0x46,
 0x46,  0x5f,  0x6a,  0x00,  0x86,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x04,  0x00,  0x00,  0x00,
 0x00,  0x00,  0x00,  0x00,  0x02,  0x10,  0x00,  0x40,  0x28,  0x00,  0x00,  0x00,  0x24,  0x00,  0x00,  0x00,
 0x14,  0x00,  0x00,  0x00,  0xf2,  0x56,  0xc3,  0x59,  0xc8,  0xbe,  0x34,  0xec,  0xd0,  0x38,  0xbc,  0x21,
 0x76,  0x76,  0x4d,  0x00,  0xe0,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x04,  0x00,  0x00,  0x00,
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
struct topic_type_name<::unitree_hg::msg::dds_::MainBoardState_>
{
    static std::string value()
    {
      return org::eclipse::cyclonedds::topic::TopicTraits<::unitree_hg::msg::dds_::MainBoardState_>::getTypeName();
    }
};

}
}

REGISTER_TOPIC_TYPE(::unitree_hg::msg::dds_::MainBoardState_)

namespace org{
namespace eclipse{
namespace cyclonedds{
namespace core{
namespace cdr{

template<>
propvec &get_type_props<::unitree_hg::msg::dds_::MainBoardState_>();

template<typename T, std::enable_if_t<std::is_base_of<cdr_stream, T>::value, bool> = true >
bool write(T& streamer, const ::unitree_hg::msg::dds_::MainBoardState_& instance, entity_properties_t *props) {
  (void)instance;
  if (!streamer.start_struct(*props))
    return false;
  auto prop = streamer.first_entity(props);
  while (prop) {
    switch (prop->m_id) {
      case 0:
      if (!streamer.start_member(*prop))
        return false;
      if (!streamer.start_consecutive(true, true))
        return false;
      if (!write(streamer, instance.fan_state()[0], instance.fan_state().size()))
        return false;
      if (!streamer.finish_consecutive())
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
      case 1:
      if (!streamer.start_member(*prop))
        return false;
      if (!streamer.start_consecutive(true, true))
        return false;
      if (!write(streamer, instance.temperature()[0], instance.temperature().size()))
        return false;
      if (!streamer.finish_consecutive())
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
      case 2:
      if (!streamer.start_member(*prop))
        return false;
      if (!streamer.start_consecutive(true, true))
        return false;
      if (!write(streamer, instance.value()[0], instance.value().size()))
        return false;
      if (!streamer.finish_consecutive())
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
      case 3:
      if (!streamer.start_member(*prop))
        return false;
      if (!streamer.start_consecutive(true, true))
        return false;
      if (!write(streamer, instance.state()[0], instance.state().size()))
        return false;
      if (!streamer.finish_consecutive())
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
bool write(S& str, const ::unitree_hg::msg::dds_::MainBoardState_& instance, bool as_key) {
  auto &props = get_type_props<::unitree_hg::msg::dds_::MainBoardState_>();
  str.set_mode(cdr_stream::stream_mode::write, as_key);
  return write(str, instance, props.data());
}

template<typename T, std::enable_if_t<std::is_base_of<cdr_stream, T>::value, bool> = true >
bool read(T& streamer, ::unitree_hg::msg::dds_::MainBoardState_& instance, entity_properties_t *props) {
  (void)instance;
  if (!streamer.start_struct(*props))
    return false;
  auto prop = streamer.first_entity(props);
  while (prop) {
    switch (prop->m_id) {
      case 0:
      if (!streamer.start_member(*prop))
        return false;
      if (!streamer.start_consecutive(true, true))
        return false;
      if (!read(streamer, instance.fan_state()[0], instance.fan_state().size()))
        return false;
      if (!streamer.finish_consecutive())
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
      case 1:
      if (!streamer.start_member(*prop))
        return false;
      if (!streamer.start_consecutive(true, true))
        return false;
      if (!read(streamer, instance.temperature()[0], instance.temperature().size()))
        return false;
      if (!streamer.finish_consecutive())
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
      case 2:
      if (!streamer.start_member(*prop))
        return false;
      if (!streamer.start_consecutive(true, true))
        return false;
      if (!read(streamer, instance.value()[0], instance.value().size()))
        return false;
      if (!streamer.finish_consecutive())
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
      case 3:
      if (!streamer.start_member(*prop))
        return false;
      if (!streamer.start_consecutive(true, true))
        return false;
      if (!read(streamer, instance.state()[0], instance.state().size()))
        return false;
      if (!streamer.finish_consecutive())
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
bool read(S& str, ::unitree_hg::msg::dds_::MainBoardState_& instance, bool as_key) {
  auto &props = get_type_props<::unitree_hg::msg::dds_::MainBoardState_>();
  str.set_mode(cdr_stream::stream_mode::read, as_key);
  return read(str, instance, props.data());
}

template<typename T, std::enable_if_t<std::is_base_of<cdr_stream, T>::value, bool> = true >
bool move(T& streamer, const ::unitree_hg::msg::dds_::MainBoardState_& instance, entity_properties_t *props) {
  (void)instance;
  if (!streamer.start_struct(*props))
    return false;
  auto prop = streamer.first_entity(props);
  while (prop) {
    switch (prop->m_id) {
      case 0:
      if (!streamer.start_member(*prop))
        return false;
      if (!streamer.start_consecutive(true, true))
        return false;
      if (!move(streamer, instance.fan_state()[0], instance.fan_state().size()))
        return false;
      if (!streamer.finish_consecutive())
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
      case 1:
      if (!streamer.start_member(*prop))
        return false;
      if (!streamer.start_consecutive(true, true))
        return false;
      if (!move(streamer, instance.temperature()[0], instance.temperature().size()))
        return false;
      if (!streamer.finish_consecutive())
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
      case 2:
      if (!streamer.start_member(*prop))
        return false;
      if (!streamer.start_consecutive(true, true))
        return false;
      if (!move(streamer, instance.value()[0], instance.value().size()))
        return false;
      if (!streamer.finish_consecutive())
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
      case 3:
      if (!streamer.start_member(*prop))
        return false;
      if (!streamer.start_consecutive(true, true))
        return false;
      if (!move(streamer, instance.state()[0], instance.state().size()))
        return false;
      if (!streamer.finish_consecutive())
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
bool move(S& str, const ::unitree_hg::msg::dds_::MainBoardState_& instance, bool as_key) {
  auto &props = get_type_props<::unitree_hg::msg::dds_::MainBoardState_>();
  str.set_mode(cdr_stream::stream_mode::move, as_key);
  return move(str, instance, props.data());
}

template<typename T, std::enable_if_t<std::is_base_of<cdr_stream, T>::value, bool> = true >
bool max(T& streamer, const ::unitree_hg::msg::dds_::MainBoardState_& instance, entity_properties_t *props) {
  (void)instance;
  if (!streamer.start_struct(*props))
    return false;
  auto prop = streamer.first_entity(props);
  while (prop) {
    switch (prop->m_id) {
      case 0:
      if (!streamer.start_member(*prop))
        return false;
      if (!streamer.start_consecutive(true, true))
        return false;
      if (!max(streamer, instance.fan_state()[0], instance.fan_state().size()))
        return false;
      if (!streamer.finish_consecutive())
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
      case 1:
      if (!streamer.start_member(*prop))
        return false;
      if (!streamer.start_consecutive(true, true))
        return false;
      if (!max(streamer, instance.temperature()[0], instance.temperature().size()))
        return false;
      if (!streamer.finish_consecutive())
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
      case 2:
      if (!streamer.start_member(*prop))
        return false;
      if (!streamer.start_consecutive(true, true))
        return false;
      if (!max(streamer, instance.value()[0], instance.value().size()))
        return false;
      if (!streamer.finish_consecutive())
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
      case 3:
      if (!streamer.start_member(*prop))
        return false;
      if (!streamer.start_consecutive(true, true))
        return false;
      if (!max(streamer, instance.state()[0], instance.state().size()))
        return false;
      if (!streamer.finish_consecutive())
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
bool max(S& str, const ::unitree_hg::msg::dds_::MainBoardState_& instance, bool as_key) {
  auto &props = get_type_props<::unitree_hg::msg::dds_::MainBoardState_>();
  str.set_mode(cdr_stream::stream_mode::max, as_key);
  return max(str, instance, props.data());
}

} //namespace cdr
} //namespace core
} //namespace cyclonedds
} //namespace eclipse
} //namespace org

#endif // DDSCXX_UNITREE_IDL_HG_MAINBOARDSTATE__HPP
