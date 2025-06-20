/****************************************************************

  Generated by Eclipse Cyclone DDS IDL to CXX Translator
  File name: VoxelMapCompressed_.idl
  Source: VoxelMapCompressed_.hpp
  Cyclone DDS: v0.10.2

*****************************************************************/
#ifndef DDSCXX_UNITREE_IDL_GO2_VOXELMAPCOMPRESSED__HPP
#define DDSCXX_UNITREE_IDL_GO2_VOXELMAPCOMPRESSED__HPP

#include <cstdint>
#include <array>
#include <vector>
#include <string>

namespace unitree_go
{
namespace msg
{
namespace dds_
{
class VoxelMapCompressed_
{
private:
 double stamp_ = 0.0;
 std::string frame_id_;
 double resolution_ = 0.0;
 std::array<double, 3> origin_ = { };
 std::array<uint16_t, 3> width_ = { };
 uint64_t src_size_ = 0;
 std::vector<uint8_t> data_;

public:
  VoxelMapCompressed_() = default;

  explicit VoxelMapCompressed_(
    double stamp,
    const std::string& frame_id,
    double resolution,
    const std::array<double, 3>& origin,
    const std::array<uint16_t, 3>& width,
    uint64_t src_size,
    const std::vector<uint8_t>& data) :
    stamp_(stamp),
    frame_id_(frame_id),
    resolution_(resolution),
    origin_(origin),
    width_(width),
    src_size_(src_size),
    data_(data) { }

  double stamp() const { return this->stamp_; }
  double& stamp() { return this->stamp_; }
  void stamp(double _val_) { this->stamp_ = _val_; }
  const std::string& frame_id() const { return this->frame_id_; }
  std::string& frame_id() { return this->frame_id_; }
  void frame_id(const std::string& _val_) { this->frame_id_ = _val_; }
  void frame_id(std::string&& _val_) { this->frame_id_ = _val_; }
  double resolution() const { return this->resolution_; }
  double& resolution() { return this->resolution_; }
  void resolution(double _val_) { this->resolution_ = _val_; }
  const std::array<double, 3>& origin() const { return this->origin_; }
  std::array<double, 3>& origin() { return this->origin_; }
  void origin(const std::array<double, 3>& _val_) { this->origin_ = _val_; }
  void origin(std::array<double, 3>&& _val_) { this->origin_ = _val_; }
  const std::array<uint16_t, 3>& width() const { return this->width_; }
  std::array<uint16_t, 3>& width() { return this->width_; }
  void width(const std::array<uint16_t, 3>& _val_) { this->width_ = _val_; }
  void width(std::array<uint16_t, 3>&& _val_) { this->width_ = _val_; }
  uint64_t src_size() const { return this->src_size_; }
  uint64_t& src_size() { return this->src_size_; }
  void src_size(uint64_t _val_) { this->src_size_ = _val_; }
  const std::vector<uint8_t>& data() const { return this->data_; }
  std::vector<uint8_t>& data() { return this->data_; }
  void data(const std::vector<uint8_t>& _val_) { this->data_ = _val_; }
  void data(std::vector<uint8_t>&& _val_) { this->data_ = _val_; }

  bool operator==(const VoxelMapCompressed_& _other) const
  {
    (void) _other;
    return stamp_ == _other.stamp_ &&
      frame_id_ == _other.frame_id_ &&
      resolution_ == _other.resolution_ &&
      origin_ == _other.origin_ &&
      width_ == _other.width_ &&
      src_size_ == _other.src_size_ &&
      data_ == _other.data_;
  }

  bool operator!=(const VoxelMapCompressed_& _other) const
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

template <> constexpr const char* TopicTraits<::unitree_go::msg::dds_::VoxelMapCompressed_>::getTypeName()
{
  return "unitree_go::msg::dds_::VoxelMapCompressed_";
}

template <> constexpr bool TopicTraits<::unitree_go::msg::dds_::VoxelMapCompressed_>::isSelfContained()
{
  return false;
}

template <> constexpr bool TopicTraits<::unitree_go::msg::dds_::VoxelMapCompressed_>::isKeyless()
{
  return true;
}

#ifdef DDSCXX_HAS_TYPE_DISCOVERY
template<> constexpr unsigned int TopicTraits<::unitree_go::msg::dds_::VoxelMapCompressed_>::type_map_blob_sz() { return 538; }
template<> constexpr unsigned int TopicTraits<::unitree_go::msg::dds_::VoxelMapCompressed_>::type_info_blob_sz() { return 100; }
template<> inline const uint8_t * TopicTraits<::unitree_go::msg::dds_::VoxelMapCompressed_>::type_map_blob() {
  static const uint8_t blob[] = {
 0xb8,  0x00,  0x00,  0x00,  0x01,  0x00,  0x00,  0x00,  0xf1,  0xf4,  0x58,  0xe7,  0x8f,  0x62,  0xc9,  0xad,
 0xbc,  0x43,  0x1d,  0x16,  0x4e,  0xdf,  0xdd,  0x00,  0xa0,  0x00,  0x00,  0x00,  0xf1,  0x51,  0x01,  0x00,
 0x01,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x90,  0x00,  0x00,  0x00,  0x07,  0x00,  0x00,  0x00,
 0x0b,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x01,  0x00,  0x0a,  0x96,  0xb8,  0xc7,  0x8d,  0x00,
 0x0c,  0x00,  0x00,  0x00,  0x01,  0x00,  0x00,  0x00,  0x01,  0x00,  0x70,  0x00,  0x4b,  0xb3,  0x9c,  0x5c,
 0x0b,  0x00,  0x00,  0x00,  0x02,  0x00,  0x00,  0x00,  0x01,  0x00,  0x0a,  0xb7,  0xe1,  0x64,  0xb3,  0x00,
 0x16,  0x00,  0x00,  0x00,  0x03,  0x00,  0x00,  0x00,  0x01,  0x00,  0x90,  0xf3,  0x01,  0x00,  0x00,  0x00,
 0x01,  0x00,  0x00,  0x00,  0x03,  0x0a,  0x7c,  0x49,  0xb1,  0x53,  0x00,  0x00,  0x16,  0x00,  0x00,  0x00,
 0x04,  0x00,  0x00,  0x00,  0x01,  0x00,  0x90,  0xf3,  0x01,  0x00,  0x00,  0x00,  0x01,  0x00,  0x00,  0x00,
 0x03,  0x06,  0xea,  0xae,  0x26,  0xa6,  0x00,  0x00,  0x0b,  0x00,  0x00,  0x00,  0x05,  0x00,  0x00,  0x00,
 0x01,  0x00,  0x08,  0x20,  0x1e,  0x06,  0xae,  0x00,  0x10,  0x00,  0x00,  0x00,  0x06,  0x00,  0x00,  0x00,
 0x01,  0x00,  0x80,  0xf3,  0x01,  0x00,  0x00,  0x02,  0x8d,  0x77,  0x7f,  0x38,  0x33,  0x01,  0x00,  0x00,
 0x01,  0x00,  0x00,  0x00,  0xf2,  0x07,  0xc6,  0xdb,  0x76,  0xf0,  0x34,  0x86,  0x2a,  0x75,  0x47,  0x5e,
 0xd7,  0xa4,  0x76,  0x00,  0x1b,  0x01,  0x00,  0x00,  0xf2,  0x51,  0x01,  0x00,  0x33,  0x00,  0x00,  0x00,
 0x00,  0x00,  0x00,  0x00,  0x2b,  0x00,  0x00,  0x00,  0x75,  0x6e,  0x69,  0x74,  0x72,  0x65,  0x65,  0x5f,
 0x67,  0x6f,  0x3a,  0x3a,  0x6d,  0x73,  0x67,  0x3a,  0x3a,  0x64,  0x64,  0x73,  0x5f,  0x3a,  0x3a,  0x56,
 0x6f,  0x78,  0x65,  0x6c,  0x4d,  0x61,  0x70,  0x43,  0x6f,  0x6d,  0x70,  0x72,  0x65,  0x73,  0x73,  0x65,
 0x64,  0x5f,  0x00,  0x00,  0xdb,  0x00,  0x00,  0x00,  0x07,  0x00,  0x00,  0x00,  0x14,  0x00,  0x00,  0x00,
 0x00,  0x00,  0x00,  0x00,  0x01,  0x00,  0x0a,  0x00,  0x06,  0x00,  0x00,  0x00,  0x73,  0x74,  0x61,  0x6d,
 0x70,  0x00,  0x00,  0x00,  0x17,  0x00,  0x00,  0x00,  0x01,  0x00,  0x00,  0x00,  0x01,  0x00,  0x70,  0x00,
 0x09,  0x00,  0x00,  0x00,  0x66,  0x72,  0x61,  0x6d,  0x65,  0x5f,  0x69,  0x64,  0x00,  0x00,  0x00,  0x00,
 0x19,  0x00,  0x00,  0x00,  0x02,  0x00,  0x00,  0x00,  0x01,  0x00,  0x0a,  0x00,  0x0b,  0x00,  0x00,  0x00,
 0x72,  0x65,  0x73,  0x6f,  0x6c,  0x75,  0x74,  0x69,  0x6f,  0x6e,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
 0x21,  0x00,  0x00,  0x00,  0x03,  0x00,  0x00,  0x00,  0x01,  0x00,  0x90,  0xf3,  0x01,  0x00,  0x00,  0x00,
 0x01,  0x00,  0x00,  0x00,  0x03,  0x0a,  0x00,  0x00,  0x07,  0x00,  0x00,  0x00,  0x6f,  0x72,  0x69,  0x67,
 0x69,  0x6e,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x20,  0x00,  0x00,  0x00,  0x04,  0x00,  0x00,  0x00,
 0x01,  0x00,  0x90,  0xf3,  0x01,  0x00,  0x00,  0x00,  0x01,  0x00,  0x00,  0x00,  0x03,  0x06,  0x00,  0x00,
 0x06,  0x00,  0x00,  0x00,  0x77,  0x69,  0x64,  0x74,  0x68,  0x00,  0x00,  0x00,  0x17,  0x00,  0x00,  0x00,
 0x05,  0x00,  0x00,  0x00,  0x01,  0x00,  0x08,  0x00,  0x09,  0x00,  0x00,  0x00,  0x73,  0x72,  0x63,  0x5f,
 0x73,  0x69,  0x7a,  0x65,  0x00,  0x00,  0x00,  0x00,  0x17,  0x00,  0x00,  0x00,  0x06,  0x00,  0x00,  0x00,
 0x01,  0x00,  0x80,  0xf3,  0x01,  0x00,  0x00,  0x02,  0x05,  0x00,  0x00,  0x00,  0x64,  0x61,  0x74,  0x61,
 0x00,  0x00,  0x00,  0x00,  0x22,  0x00,  0x00,  0x00,  0x01,  0x00,  0x00,  0x00,  0xf2,  0x07,  0xc6,  0xdb,
 0x76,  0xf0,  0x34,  0x86,  0x2a,  0x75,  0x47,  0x5e,  0xd7,  0xa4,  0x76,  0xf1,  0xf4,  0x58,  0xe7,  0x8f,
 0x62,  0xc9,  0xad,  0xbc,  0x43,  0x1d,  0x16,  0x4e,  0xdf,  0xdd, };
  return blob;
}
template<> inline const uint8_t * TopicTraits<::unitree_go::msg::dds_::VoxelMapCompressed_>::type_info_blob() {
  static const uint8_t blob[] = {
 0x60,  0x00,  0x00,  0x00,  0x01,  0x10,  0x00,  0x40,  0x28,  0x00,  0x00,  0x00,  0x24,  0x00,  0x00,  0x00,
 0x14,  0x00,  0x00,  0x00,  0xf1,  0xf4,  0x58,  0xe7,  0x8f,  0x62,  0xc9,  0xad,  0xbc,  0x43,  0x1d,  0x16,
 0x4e,  0xdf,  0xdd,  0x00,  0xa4,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x04,  0x00,  0x00,  0x00,
 0x00,  0x00,  0x00,  0x00,  0x02,  0x10,  0x00,  0x40,  0x28,  0x00,  0x00,  0x00,  0x24,  0x00,  0x00,  0x00,
 0x14,  0x00,  0x00,  0x00,  0xf2,  0x07,  0xc6,  0xdb,  0x76,  0xf0,  0x34,  0x86,  0x2a,  0x75,  0x47,  0x5e,
 0xd7,  0xa4,  0x76,  0x00,  0x1f,  0x01,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x04,  0x00,  0x00,  0x00,
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
struct topic_type_name<::unitree_go::msg::dds_::VoxelMapCompressed_>
{
    static std::string value()
    {
      return org::eclipse::cyclonedds::topic::TopicTraits<::unitree_go::msg::dds_::VoxelMapCompressed_>::getTypeName();
    }
};

}
}

REGISTER_TOPIC_TYPE(::unitree_go::msg::dds_::VoxelMapCompressed_)

namespace org{
namespace eclipse{
namespace cyclonedds{
namespace core{
namespace cdr{

template<>
propvec &get_type_props<::unitree_go::msg::dds_::VoxelMapCompressed_>();

template<typename T, std::enable_if_t<std::is_base_of<cdr_stream, T>::value, bool> = true >
bool write(T& streamer, const ::unitree_go::msg::dds_::VoxelMapCompressed_& instance, entity_properties_t *props) {
  (void)instance;
  if (!streamer.start_struct(*props))
    return false;
  auto prop = streamer.first_entity(props);
  while (prop) {
    switch (prop->m_id) {
      case 0:
      if (!streamer.start_member(*prop))
        return false;
      if (!write(streamer, instance.stamp()))
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
      case 1:
      if (!streamer.start_member(*prop))
        return false;
      if (!write_string(streamer, instance.frame_id(), 0))
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
      case 2:
      if (!streamer.start_member(*prop))
        return false;
      if (!write(streamer, instance.resolution()))
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
      case 3:
      if (!streamer.start_member(*prop))
        return false;
      if (!streamer.start_consecutive(true, true))
        return false;
      if (!write(streamer, instance.origin()[0], instance.origin().size()))
        return false;
      if (!streamer.finish_consecutive())
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
      case 4:
      if (!streamer.start_member(*prop))
        return false;
      if (!streamer.start_consecutive(true, true))
        return false;
      if (!write(streamer, instance.width()[0], instance.width().size()))
        return false;
      if (!streamer.finish_consecutive())
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
      case 5:
      if (!streamer.start_member(*prop))
        return false;
      if (!write(streamer, instance.src_size()))
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
      case 6:
      if (!streamer.start_member(*prop))
        return false;
      if (!streamer.start_consecutive(false, true))
        return false;
      {
      uint32_t se_1 = uint32_t(instance.data().size());
      if (!write(streamer, se_1))
        return false;
      if (se_1 > 0 &&
          !write(streamer, instance.data()[0], se_1))
        return false;
      }  //end sequence 1
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
bool write(S& str, const ::unitree_go::msg::dds_::VoxelMapCompressed_& instance, bool as_key) {
  auto &props = get_type_props<::unitree_go::msg::dds_::VoxelMapCompressed_>();
  str.set_mode(cdr_stream::stream_mode::write, as_key);
  return write(str, instance, props.data());
}

template<typename T, std::enable_if_t<std::is_base_of<cdr_stream, T>::value, bool> = true >
bool read(T& streamer, ::unitree_go::msg::dds_::VoxelMapCompressed_& instance, entity_properties_t *props) {
  (void)instance;
  if (!streamer.start_struct(*props))
    return false;
  auto prop = streamer.first_entity(props);
  while (prop) {
    switch (prop->m_id) {
      case 0:
      if (!streamer.start_member(*prop))
        return false;
      if (!read(streamer, instance.stamp()))
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
      case 1:
      if (!streamer.start_member(*prop))
        return false;
      if (!read_string(streamer, instance.frame_id(), 0))
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
      case 2:
      if (!streamer.start_member(*prop))
        return false;
      if (!read(streamer, instance.resolution()))
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
      case 3:
      if (!streamer.start_member(*prop))
        return false;
      if (!streamer.start_consecutive(true, true))
        return false;
      if (!read(streamer, instance.origin()[0], instance.origin().size()))
        return false;
      if (!streamer.finish_consecutive())
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
      case 4:
      if (!streamer.start_member(*prop))
        return false;
      if (!streamer.start_consecutive(true, true))
        return false;
      if (!read(streamer, instance.width()[0], instance.width().size()))
        return false;
      if (!streamer.finish_consecutive())
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
      case 5:
      if (!streamer.start_member(*prop))
        return false;
      if (!read(streamer, instance.src_size()))
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
      case 6:
      if (!streamer.start_member(*prop))
        return false;
      if (!streamer.start_consecutive(false, true))
        return false;
      {
      uint32_t se_1 = uint32_t(instance.data().size());
      if (!read(streamer, se_1))
        return false;
      instance.data().resize(se_1);
      if (se_1 > 0 &&
          !read(streamer, instance.data()[0], se_1))
        return false;
      }  //end sequence 1
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
bool read(S& str, ::unitree_go::msg::dds_::VoxelMapCompressed_& instance, bool as_key) {
  auto &props = get_type_props<::unitree_go::msg::dds_::VoxelMapCompressed_>();
  str.set_mode(cdr_stream::stream_mode::read, as_key);
  return read(str, instance, props.data());
}

template<typename T, std::enable_if_t<std::is_base_of<cdr_stream, T>::value, bool> = true >
bool move(T& streamer, const ::unitree_go::msg::dds_::VoxelMapCompressed_& instance, entity_properties_t *props) {
  (void)instance;
  if (!streamer.start_struct(*props))
    return false;
  auto prop = streamer.first_entity(props);
  while (prop) {
    switch (prop->m_id) {
      case 0:
      if (!streamer.start_member(*prop))
        return false;
      if (!move(streamer, instance.stamp()))
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
      case 1:
      if (!streamer.start_member(*prop))
        return false;
      if (!move_string(streamer, instance.frame_id(), 0))
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
      case 2:
      if (!streamer.start_member(*prop))
        return false;
      if (!move(streamer, instance.resolution()))
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
      case 3:
      if (!streamer.start_member(*prop))
        return false;
      if (!streamer.start_consecutive(true, true))
        return false;
      if (!move(streamer, instance.origin()[0], instance.origin().size()))
        return false;
      if (!streamer.finish_consecutive())
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
      case 4:
      if (!streamer.start_member(*prop))
        return false;
      if (!streamer.start_consecutive(true, true))
        return false;
      if (!move(streamer, instance.width()[0], instance.width().size()))
        return false;
      if (!streamer.finish_consecutive())
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
      case 5:
      if (!streamer.start_member(*prop))
        return false;
      if (!move(streamer, instance.src_size()))
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
      case 6:
      if (!streamer.start_member(*prop))
        return false;
      if (!streamer.start_consecutive(false, true))
        return false;
      {
      uint32_t se_1 = uint32_t(instance.data().size());
      if (!move(streamer, se_1))
        return false;
      if (se_1 > 0 &&
          !move(streamer, uint8_t(), se_1))
        return false;
      }  //end sequence 1
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
bool move(S& str, const ::unitree_go::msg::dds_::VoxelMapCompressed_& instance, bool as_key) {
  auto &props = get_type_props<::unitree_go::msg::dds_::VoxelMapCompressed_>();
  str.set_mode(cdr_stream::stream_mode::move, as_key);
  return move(str, instance, props.data());
}

template<typename T, std::enable_if_t<std::is_base_of<cdr_stream, T>::value, bool> = true >
bool max(T& streamer, const ::unitree_go::msg::dds_::VoxelMapCompressed_& instance, entity_properties_t *props) {
  (void)instance;
  if (!streamer.start_struct(*props))
    return false;
  auto prop = streamer.first_entity(props);
  while (prop) {
    switch (prop->m_id) {
      case 0:
      if (!streamer.start_member(*prop))
        return false;
      if (!max(streamer, instance.stamp()))
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
      case 1:
      if (!streamer.start_member(*prop))
        return false;
      if (!max_string(streamer, instance.frame_id(), 0))
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
      case 2:
      if (!streamer.start_member(*prop))
        return false;
      if (!max(streamer, instance.resolution()))
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
      case 3:
      if (!streamer.start_member(*prop))
        return false;
      if (!streamer.start_consecutive(true, true))
        return false;
      if (!max(streamer, instance.origin()[0], instance.origin().size()))
        return false;
      if (!streamer.finish_consecutive())
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
      case 4:
      if (!streamer.start_member(*prop))
        return false;
      if (!streamer.start_consecutive(true, true))
        return false;
      if (!max(streamer, instance.width()[0], instance.width().size()))
        return false;
      if (!streamer.finish_consecutive())
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
      case 5:
      if (!streamer.start_member(*prop))
        return false;
      if (!max(streamer, instance.src_size()))
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
      case 6:
      if (!streamer.start_member(*prop))
        return false;
      if (!streamer.start_consecutive(false, true))
        return false;
      {
      uint32_t se_1 = 0;
      if (!max(streamer, se_1))
        return false;
      if (se_1 > 0 &&
          !max(streamer, uint8_t(), se_1))
        return false;
      }  //end sequence 1
      if (!streamer.finish_consecutive())
        return false;
      streamer.position(SIZE_MAX);
      if (!streamer.finish_member(*prop))
        return false;
      break;
    }
    prop = streamer.next_entity(prop);
  }
  return streamer.finish_struct(*props);
}

template<typename S, std::enable_if_t<std::is_base_of<cdr_stream, S>::value, bool> = true >
bool max(S& str, const ::unitree_go::msg::dds_::VoxelMapCompressed_& instance, bool as_key) {
  auto &props = get_type_props<::unitree_go::msg::dds_::VoxelMapCompressed_>();
  str.set_mode(cdr_stream::stream_mode::max, as_key);
  return max(str, instance, props.data());
}

} //namespace cdr
} //namespace core
} //namespace cyclonedds
} //namespace eclipse
} //namespace org

#endif // DDSCXX_UNITREE_IDL_GO2_VOXELMAPCOMPRESSED__HPP
