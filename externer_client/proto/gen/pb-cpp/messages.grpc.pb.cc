// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: messages.proto

#include "messages.pb.h"
#include "messages.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace messages {

static const char* serverActions_method_names[] = {
  "/messages.serverActions/turnOff",
  "/messages.serverActions/turnOn",
};

std::unique_ptr< serverActions::Stub> serverActions::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< serverActions::Stub> stub(new serverActions::Stub(channel));
  return stub;
}

serverActions::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_turnOff_(serverActions_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_turnOn_(serverActions_method_names[1], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status serverActions::Stub::turnOff(::grpc::ClientContext* context, const ::messages::Void& request, ::messages::Bool* response) {
  return ::grpc::internal::BlockingUnaryCall< ::messages::Void, ::messages::Bool, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_turnOff_, context, request, response);
}

void serverActions::Stub::experimental_async::turnOff(::grpc::ClientContext* context, const ::messages::Void* request, ::messages::Bool* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::messages::Void, ::messages::Bool, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_turnOff_, context, request, response, std::move(f));
}

void serverActions::Stub::experimental_async::turnOff(::grpc::ClientContext* context, const ::messages::Void* request, ::messages::Bool* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_turnOff_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::messages::Bool>* serverActions::Stub::PrepareAsyncturnOffRaw(::grpc::ClientContext* context, const ::messages::Void& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::messages::Bool, ::messages::Void, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_turnOff_, context, request);
}

::grpc::ClientAsyncResponseReader< ::messages::Bool>* serverActions::Stub::AsyncturnOffRaw(::grpc::ClientContext* context, const ::messages::Void& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncturnOffRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status serverActions::Stub::turnOn(::grpc::ClientContext* context, const ::messages::Void& request, ::messages::Bool* response) {
  return ::grpc::internal::BlockingUnaryCall< ::messages::Void, ::messages::Bool, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_turnOn_, context, request, response);
}

void serverActions::Stub::experimental_async::turnOn(::grpc::ClientContext* context, const ::messages::Void* request, ::messages::Bool* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::messages::Void, ::messages::Bool, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_turnOn_, context, request, response, std::move(f));
}

void serverActions::Stub::experimental_async::turnOn(::grpc::ClientContext* context, const ::messages::Void* request, ::messages::Bool* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_turnOn_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::messages::Bool>* serverActions::Stub::PrepareAsyncturnOnRaw(::grpc::ClientContext* context, const ::messages::Void& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::messages::Bool, ::messages::Void, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_turnOn_, context, request);
}

::grpc::ClientAsyncResponseReader< ::messages::Bool>* serverActions::Stub::AsyncturnOnRaw(::grpc::ClientContext* context, const ::messages::Void& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncturnOnRaw(context, request, cq);
  result->StartCall();
  return result;
}

serverActions::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      serverActions_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< serverActions::Service, ::messages::Void, ::messages::Bool, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](serverActions::Service* service,
             ::grpc::ServerContext* ctx,
             const ::messages::Void* req,
             ::messages::Bool* resp) {
               return service->turnOff(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      serverActions_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< serverActions::Service, ::messages::Void, ::messages::Bool, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](serverActions::Service* service,
             ::grpc::ServerContext* ctx,
             const ::messages::Void* req,
             ::messages::Bool* resp) {
               return service->turnOn(ctx, req, resp);
             }, this)));
}

serverActions::Service::~Service() {
}

::grpc::Status serverActions::Service::turnOff(::grpc::ServerContext* context, const ::messages::Void* request, ::messages::Bool* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status serverActions::Service::turnOn(::grpc::ServerContext* context, const ::messages::Void* request, ::messages::Bool* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace messages

