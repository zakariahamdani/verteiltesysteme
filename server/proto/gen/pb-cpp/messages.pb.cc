// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: messages.proto

#include "messages.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
namespace messages {
constexpr Void::Void(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized){}
struct VoidDefaultTypeInternal {
  constexpr VoidDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~VoidDefaultTypeInternal() {}
  union {
    Void _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT VoidDefaultTypeInternal _Void_default_instance_;
constexpr Bool::Bool(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : boolvar_(false){}
struct BoolDefaultTypeInternal {
  constexpr BoolDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~BoolDefaultTypeInternal() {}
  union {
    Bool _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT BoolDefaultTypeInternal _Bool_default_instance_;
}  // namespace messages
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_messages_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_messages_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_messages_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_messages_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::messages::Void, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::messages::Bool, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::messages::Bool, boolvar_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::messages::Void)},
  { 5, -1, sizeof(::messages::Bool)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::messages::_Void_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::messages::_Bool_default_instance_),
};

const char descriptor_table_protodef_messages_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\016messages.proto\022\010messages\"\006\n\004Void\"\027\n\004Bo"
  "ol\022\017\n\007boolVar\030\001 \001(\0102d\n\rserverActions\022)\n\007"
  "turnOff\022\016.messages.Void\032\016.messages.Bool\022"
  "(\n\006turnOn\022\016.messages.Void\032\016.messages.Boo"
  "lb\006proto3"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_messages_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_messages_2eproto = {
  false, false, 169, descriptor_table_protodef_messages_2eproto, "messages.proto", 
  &descriptor_table_messages_2eproto_once, nullptr, 0, 2,
  schemas, file_default_instances, TableStruct_messages_2eproto::offsets,
  file_level_metadata_messages_2eproto, file_level_enum_descriptors_messages_2eproto, file_level_service_descriptors_messages_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK ::PROTOBUF_NAMESPACE_ID::Metadata
descriptor_table_messages_2eproto_metadata_getter(int index) {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_messages_2eproto);
  return descriptor_table_messages_2eproto.file_level_metadata[index];
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_messages_2eproto(&descriptor_table_messages_2eproto);
namespace messages {

// ===================================================================

class Void::_Internal {
 public:
};

Void::Void(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:messages.Void)
}
Void::Void(const Void& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:messages.Void)
}

void Void::SharedCtor() {
}

Void::~Void() {
  // @@protoc_insertion_point(destructor:messages.Void)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void Void::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
}

void Void::ArenaDtor(void* object) {
  Void* _this = reinterpret_cast< Void* >(object);
  (void)_this;
}
void Void::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Void::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Void::Clear() {
// @@protoc_insertion_point(message_clear_start:messages.Void)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Void::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* Void::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:messages.Void)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:messages.Void)
  return target;
}

size_t Void::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:messages.Void)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Void::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:messages.Void)
  GOOGLE_DCHECK_NE(&from, this);
  const Void* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<Void>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:messages.Void)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:messages.Void)
    MergeFrom(*source);
  }
}

void Void::MergeFrom(const Void& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:messages.Void)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

}

void Void::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:messages.Void)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Void::CopyFrom(const Void& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:messages.Void)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Void::IsInitialized() const {
  return true;
}

void Void::InternalSwap(Void* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Void::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

class Bool::_Internal {
 public:
};

Bool::Bool(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:messages.Bool)
}
Bool::Bool(const Bool& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  boolvar_ = from.boolvar_;
  // @@protoc_insertion_point(copy_constructor:messages.Bool)
}

void Bool::SharedCtor() {
boolvar_ = false;
}

Bool::~Bool() {
  // @@protoc_insertion_point(destructor:messages.Bool)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void Bool::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
}

void Bool::ArenaDtor(void* object) {
  Bool* _this = reinterpret_cast< Bool* >(object);
  (void)_this;
}
void Bool::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Bool::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Bool::Clear() {
// @@protoc_insertion_point(message_clear_start:messages.Bool)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  boolvar_ = false;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Bool::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // bool boolVar = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          boolvar_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* Bool::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:messages.Bool)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // bool boolVar = 1;
  if (this->boolvar() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBoolToArray(1, this->_internal_boolvar(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:messages.Bool)
  return target;
}

size_t Bool::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:messages.Bool)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // bool boolVar = 1;
  if (this->boolvar() != 0) {
    total_size += 1 + 1;
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Bool::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:messages.Bool)
  GOOGLE_DCHECK_NE(&from, this);
  const Bool* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<Bool>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:messages.Bool)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:messages.Bool)
    MergeFrom(*source);
  }
}

void Bool::MergeFrom(const Bool& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:messages.Bool)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.boolvar() != 0) {
    _internal_set_boolvar(from._internal_boolvar());
  }
}

void Bool::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:messages.Bool)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Bool::CopyFrom(const Bool& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:messages.Bool)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Bool::IsInitialized() const {
  return true;
}

void Bool::InternalSwap(Bool* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  swap(boolvar_, other->boolvar_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Bool::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace messages
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::messages::Void* Arena::CreateMaybeMessage< ::messages::Void >(Arena* arena) {
  return Arena::CreateMessageInternal< ::messages::Void >(arena);
}
template<> PROTOBUF_NOINLINE ::messages::Bool* Arena::CreateMaybeMessage< ::messages::Bool >(Arena* arena) {
  return Arena::CreateMessageInternal< ::messages::Bool >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
