// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: messages.proto
#ifndef GRPC_messages_2eproto__INCLUDED
#define GRPC_messages_2eproto__INCLUDED

#include "messages.pb.h"

#include <functional>
#include <grpc/impl/codegen/port_platform.h>
#include <grpcpp/impl/codegen/async_generic_service.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/client_context.h>
#include <grpcpp/impl/codegen/completion_queue.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace messages {

class serverActions final {
 public:
  static constexpr char const* service_full_name() {
    return "messages.serverActions";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status turnOff(::grpc::ClientContext* context, const ::messages::Void& request, ::messages::Bool* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::messages::Bool>> AsyncturnOff(::grpc::ClientContext* context, const ::messages::Void& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::messages::Bool>>(AsyncturnOffRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::messages::Bool>> PrepareAsyncturnOff(::grpc::ClientContext* context, const ::messages::Void& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::messages::Bool>>(PrepareAsyncturnOffRaw(context, request, cq));
    }
    virtual ::grpc::Status turnOn(::grpc::ClientContext* context, const ::messages::Void& request, ::messages::Bool* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::messages::Bool>> AsyncturnOn(::grpc::ClientContext* context, const ::messages::Void& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::messages::Bool>>(AsyncturnOnRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::messages::Bool>> PrepareAsyncturnOn(::grpc::ClientContext* context, const ::messages::Void& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::messages::Bool>>(PrepareAsyncturnOnRaw(context, request, cq));
    }
    class experimental_async_interface {
     public:
      virtual ~experimental_async_interface() {}
      virtual void turnOff(::grpc::ClientContext* context, const ::messages::Void* request, ::messages::Bool* response, std::function<void(::grpc::Status)>) = 0;
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      virtual void turnOff(::grpc::ClientContext* context, const ::messages::Void* request, ::messages::Bool* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      #else
      virtual void turnOff(::grpc::ClientContext* context, const ::messages::Void* request, ::messages::Bool* response, ::grpc::experimental::ClientUnaryReactor* reactor) = 0;
      #endif
      virtual void turnOn(::grpc::ClientContext* context, const ::messages::Void* request, ::messages::Bool* response, std::function<void(::grpc::Status)>) = 0;
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      virtual void turnOn(::grpc::ClientContext* context, const ::messages::Void* request, ::messages::Bool* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      #else
      virtual void turnOn(::grpc::ClientContext* context, const ::messages::Void* request, ::messages::Bool* response, ::grpc::experimental::ClientUnaryReactor* reactor) = 0;
      #endif
    };
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    typedef class experimental_async_interface async_interface;
    #endif
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    async_interface* async() { return experimental_async(); }
    #endif
    virtual class experimental_async_interface* experimental_async() { return nullptr; }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::messages::Bool>* AsyncturnOffRaw(::grpc::ClientContext* context, const ::messages::Void& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::messages::Bool>* PrepareAsyncturnOffRaw(::grpc::ClientContext* context, const ::messages::Void& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::messages::Bool>* AsyncturnOnRaw(::grpc::ClientContext* context, const ::messages::Void& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::messages::Bool>* PrepareAsyncturnOnRaw(::grpc::ClientContext* context, const ::messages::Void& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    ::grpc::Status turnOff(::grpc::ClientContext* context, const ::messages::Void& request, ::messages::Bool* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::messages::Bool>> AsyncturnOff(::grpc::ClientContext* context, const ::messages::Void& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::messages::Bool>>(AsyncturnOffRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::messages::Bool>> PrepareAsyncturnOff(::grpc::ClientContext* context, const ::messages::Void& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::messages::Bool>>(PrepareAsyncturnOffRaw(context, request, cq));
    }
    ::grpc::Status turnOn(::grpc::ClientContext* context, const ::messages::Void& request, ::messages::Bool* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::messages::Bool>> AsyncturnOn(::grpc::ClientContext* context, const ::messages::Void& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::messages::Bool>>(AsyncturnOnRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::messages::Bool>> PrepareAsyncturnOn(::grpc::ClientContext* context, const ::messages::Void& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::messages::Bool>>(PrepareAsyncturnOnRaw(context, request, cq));
    }
    class experimental_async final :
      public StubInterface::experimental_async_interface {
     public:
      void turnOff(::grpc::ClientContext* context, const ::messages::Void* request, ::messages::Bool* response, std::function<void(::grpc::Status)>) override;
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      void turnOff(::grpc::ClientContext* context, const ::messages::Void* request, ::messages::Bool* response, ::grpc::ClientUnaryReactor* reactor) override;
      #else
      void turnOff(::grpc::ClientContext* context, const ::messages::Void* request, ::messages::Bool* response, ::grpc::experimental::ClientUnaryReactor* reactor) override;
      #endif
      void turnOn(::grpc::ClientContext* context, const ::messages::Void* request, ::messages::Bool* response, std::function<void(::grpc::Status)>) override;
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      void turnOn(::grpc::ClientContext* context, const ::messages::Void* request, ::messages::Bool* response, ::grpc::ClientUnaryReactor* reactor) override;
      #else
      void turnOn(::grpc::ClientContext* context, const ::messages::Void* request, ::messages::Bool* response, ::grpc::experimental::ClientUnaryReactor* reactor) override;
      #endif
     private:
      friend class Stub;
      explicit experimental_async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class experimental_async_interface* experimental_async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class experimental_async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::messages::Bool>* AsyncturnOffRaw(::grpc::ClientContext* context, const ::messages::Void& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::messages::Bool>* PrepareAsyncturnOffRaw(::grpc::ClientContext* context, const ::messages::Void& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::messages::Bool>* AsyncturnOnRaw(::grpc::ClientContext* context, const ::messages::Void& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::messages::Bool>* PrepareAsyncturnOnRaw(::grpc::ClientContext* context, const ::messages::Void& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_turnOff_;
    const ::grpc::internal::RpcMethod rpcmethod_turnOn_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status turnOff(::grpc::ServerContext* context, const ::messages::Void* request, ::messages::Bool* response);
    virtual ::grpc::Status turnOn(::grpc::ServerContext* context, const ::messages::Void* request, ::messages::Bool* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_turnOff : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_turnOff() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_turnOff() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status turnOff(::grpc::ServerContext* /*context*/, const ::messages::Void* /*request*/, ::messages::Bool* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestturnOff(::grpc::ServerContext* context, ::messages::Void* request, ::grpc::ServerAsyncResponseWriter< ::messages::Bool>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_turnOn : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_turnOn() {
      ::grpc::Service::MarkMethodAsync(1);
    }
    ~WithAsyncMethod_turnOn() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status turnOn(::grpc::ServerContext* /*context*/, const ::messages::Void* /*request*/, ::messages::Bool* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestturnOn(::grpc::ServerContext* context, ::messages::Void* request, ::grpc::ServerAsyncResponseWriter< ::messages::Bool>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_turnOff<WithAsyncMethod_turnOn<Service > > AsyncService;
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_turnOff : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithCallbackMethod_turnOff() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::messages::Void, ::messages::Bool>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context, const ::messages::Void* request, ::messages::Bool* response) { return this->turnOff(context, request, response); }));}
    void SetMessageAllocatorFor_turnOff(
        ::grpc::experimental::MessageAllocator< ::messages::Void, ::messages::Bool>* allocator) {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(0);
    #else
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::experimental().GetHandler(0);
    #endif
      static_cast<::grpc::internal::CallbackUnaryHandler< ::messages::Void, ::messages::Bool>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~ExperimentalWithCallbackMethod_turnOff() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status turnOff(::grpc::ServerContext* /*context*/, const ::messages::Void* /*request*/, ::messages::Bool* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerUnaryReactor* turnOff(
      ::grpc::CallbackServerContext* /*context*/, const ::messages::Void* /*request*/, ::messages::Bool* /*response*/)
    #else
    virtual ::grpc::experimental::ServerUnaryReactor* turnOff(
      ::grpc::experimental::CallbackServerContext* /*context*/, const ::messages::Void* /*request*/, ::messages::Bool* /*response*/)
    #endif
      { return nullptr; }
  };
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_turnOn : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithCallbackMethod_turnOn() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodCallback(1,
          new ::grpc::internal::CallbackUnaryHandler< ::messages::Void, ::messages::Bool>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context, const ::messages::Void* request, ::messages::Bool* response) { return this->turnOn(context, request, response); }));}
    void SetMessageAllocatorFor_turnOn(
        ::grpc::experimental::MessageAllocator< ::messages::Void, ::messages::Bool>* allocator) {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(1);
    #else
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::experimental().GetHandler(1);
    #endif
      static_cast<::grpc::internal::CallbackUnaryHandler< ::messages::Void, ::messages::Bool>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~ExperimentalWithCallbackMethod_turnOn() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status turnOn(::grpc::ServerContext* /*context*/, const ::messages::Void* /*request*/, ::messages::Bool* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerUnaryReactor* turnOn(
      ::grpc::CallbackServerContext* /*context*/, const ::messages::Void* /*request*/, ::messages::Bool* /*response*/)
    #else
    virtual ::grpc::experimental::ServerUnaryReactor* turnOn(
      ::grpc::experimental::CallbackServerContext* /*context*/, const ::messages::Void* /*request*/, ::messages::Bool* /*response*/)
    #endif
      { return nullptr; }
  };
  #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
  typedef ExperimentalWithCallbackMethod_turnOff<ExperimentalWithCallbackMethod_turnOn<Service > > CallbackService;
  #endif

  typedef ExperimentalWithCallbackMethod_turnOff<ExperimentalWithCallbackMethod_turnOn<Service > > ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_turnOff : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_turnOff() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_turnOff() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status turnOff(::grpc::ServerContext* /*context*/, const ::messages::Void* /*request*/, ::messages::Bool* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_turnOn : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_turnOn() {
      ::grpc::Service::MarkMethodGeneric(1);
    }
    ~WithGenericMethod_turnOn() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status turnOn(::grpc::ServerContext* /*context*/, const ::messages::Void* /*request*/, ::messages::Bool* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_turnOff : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_turnOff() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_turnOff() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status turnOff(::grpc::ServerContext* /*context*/, const ::messages::Void* /*request*/, ::messages::Bool* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestturnOff(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_turnOn : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_turnOn() {
      ::grpc::Service::MarkMethodRaw(1);
    }
    ~WithRawMethod_turnOn() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status turnOn(::grpc::ServerContext* /*context*/, const ::messages::Void* /*request*/, ::messages::Bool* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestturnOn(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_turnOff : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithRawCallbackMethod_turnOff() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodRawCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->turnOff(context, request, response); }));
    }
    ~ExperimentalWithRawCallbackMethod_turnOff() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status turnOff(::grpc::ServerContext* /*context*/, const ::messages::Void* /*request*/, ::messages::Bool* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerUnaryReactor* turnOff(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)
    #else
    virtual ::grpc::experimental::ServerUnaryReactor* turnOff(
      ::grpc::experimental::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)
    #endif
      { return nullptr; }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_turnOn : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithRawCallbackMethod_turnOn() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodRawCallback(1,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->turnOn(context, request, response); }));
    }
    ~ExperimentalWithRawCallbackMethod_turnOn() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status turnOn(::grpc::ServerContext* /*context*/, const ::messages::Void* /*request*/, ::messages::Bool* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerUnaryReactor* turnOn(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)
    #else
    virtual ::grpc::experimental::ServerUnaryReactor* turnOn(
      ::grpc::experimental::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)
    #endif
      { return nullptr; }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_turnOff : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_turnOff() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler<
          ::messages::Void, ::messages::Bool>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::messages::Void, ::messages::Bool>* streamer) {
                       return this->StreamedturnOff(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_turnOff() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status turnOff(::grpc::ServerContext* /*context*/, const ::messages::Void* /*request*/, ::messages::Bool* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedturnOff(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::messages::Void,::messages::Bool>* server_unary_streamer) = 0;
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_turnOn : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_turnOn() {
      ::grpc::Service::MarkMethodStreamed(1,
        new ::grpc::internal::StreamedUnaryHandler<
          ::messages::Void, ::messages::Bool>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::messages::Void, ::messages::Bool>* streamer) {
                       return this->StreamedturnOn(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_turnOn() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status turnOn(::grpc::ServerContext* /*context*/, const ::messages::Void* /*request*/, ::messages::Bool* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedturnOn(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::messages::Void,::messages::Bool>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_turnOff<WithStreamedUnaryMethod_turnOn<Service > > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_turnOff<WithStreamedUnaryMethod_turnOn<Service > > StreamedService;
};

}  // namespace messages


#endif  // GRPC_messages_2eproto__INCLUDED
