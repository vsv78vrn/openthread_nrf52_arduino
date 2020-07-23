#include "OpenThread.h"


OT_DECL__FUNC(1, BackboneRouter, otError, GetPrimary, otBackboneRouterConfig*)
OT_DECL__FUNC(0, BackboneRouter, otBackboneRouterState, GetState)
OT_DECL__FUNC(0, BackboneRouter, otError, Register)
OT_DECL__FUNC(0, BackboneRouter, uint8_t, GetRegistrationJitter)
OT_DECL_VFUNC(1, BackboneRouter, void, GetConfig, otBackboneRouterConfig*)
OT_DECL_VFUNC(1, BackboneRouter, void, SetConfig, const otBackboneRouterConfig*)
OT_DECL_VFUNC(1, BackboneRouter, void, SetEnabled, bool)
OT_DECL_VFUNC(1, BackboneRouter, void, SetRegistrationJitter, uint8_t)
OT_DECL__FUNC(0, BorderAgent, otBorderAgentState, GetState)
OT_DECL__FUNC(1, BorderRouter, otError, AddOnMeshPrefix, const otBorderRouterConfig*)
OT_DECL__FUNC(1, BorderRouter, otError, AddRoute, const otExternalRouteConfig*)
OT_DECL__FUNC(3, BorderRouter, otError, GetNetData, bool, uint8_t*, uint8_t*)
OT_DECL__FUNC(2, BorderRouter, otError, GetNextOnMeshPrefix, otNetworkDataIterator*, otBorderRouterConfig*)
OT_DECL__FUNC(2, BorderRouter, otError, GetNextRoute, otNetworkDataIterator*, otExternalRouteConfig*)
OT_DECL__FUNC(0, BorderRouter, otError, Register)
OT_DECL__FUNC(1, BorderRouter, otError, RemoveOnMeshPrefix, const otIp6Prefix*)
OT_DECL__FUNC(1, BorderRouter, otError, RemoveRoute, const otIp6Prefix*)
OT_DECL__FUNC(0, ChannelManager, bool, GetAutoChannelSelectionEnabled)
OT_DECL__FUNC(1, ChannelManager, otError, RequestChannelSelect, bool)
OT_DECL__FUNC(1, ChannelManager, otError, SetAutoChannelSelectionInterval, uint32_t)
OT_DECL__FUNC(1, ChannelManager, otError, SetDelay, uint16_t)
OT_DECL__FUNC(0, ChannelManager, uint16_t, GetDelay)
OT_DECL__FUNC(0, ChannelManager, uint32_t, GetAutoChannelSelectionInterval)
OT_DECL__FUNC(0, ChannelManager, uint32_t, GetFavoredChannels)
OT_DECL__FUNC(0, ChannelManager, uint32_t, GetSupportedChannels)
OT_DECL__FUNC(0, ChannelManager, uint8_t, GetRequestedChannel)
OT_DECL_VFUNC(1, ChannelManager, void, RequestChannelChange, uint8_t)
OT_DECL_VFUNC(1, ChannelManager, void, SetAutoChannelSelectionEnabled, bool)
OT_DECL_VFUNC(1, ChannelManager, void, SetFavoredChannels, uint32_t)
OT_DECL_VFUNC(1, ChannelManager, void, SetSupportedChannels, uint32_t)
OT_DECL__FUNC(0, ChannelMonitor, bool, IsEnabled)
OT_DECL__FUNC(0, ChannelMonitor, int8_t, GetRssiThreshold)
OT_DECL__FUNC(1, ChannelMonitor, otError, SetEnabled, bool)
OT_DECL__FUNC(1, ChannelMonitor, uint16_t, GetChannelOccupancy, uint8_t)
OT_DECL__FUNC(0, ChannelMonitor, uint32_t, GetSampleCount)
OT_DECL__FUNC(0, ChannelMonitor, uint32_t, GetSampleInterval)
OT_DECL__FUNC(0, ChannelMonitor, uint32_t, GetSampleWindow)
OT_DECL__FUNC(0, ChildSupervision, uint16_t, GetCheckTimeout)
OT_DECL__FUNC(0, ChildSupervision, uint16_t, GetInterval)
OT_DECL_VFUNC(1, ChildSupervision, void, SetCheckTimeout, uint16_t)
OT_DECL_VFUNC(1, ChildSupervision, void, SetInterval, uint16_t)
void OpenThreadClass::OpenThreadCliClass::AppendResult(otError a) { return otCliAppendResult(a); }
OT_DECL_VFUNC(2, Cli, void, ConsoleInit, otCliConsoleOutputCallback, void*)
void OpenThreadClass::OpenThreadCliClass::ConsoleInputLine(char* a, uint16_t b) { return otCliConsoleInputLine(a, b); }
void OpenThreadClass::OpenThreadCliClass::Output(const char* a, uint16_t b) { return otCliOutput(a,b); }
void OpenThreadClass::OpenThreadCliClass::OutputBytes(const uint8_t* a, uint8_t b) { return otCliOutputBytes(a, b); }
//void OpenThreadClass::OpenThreadCliClass::OutputFormat(const char*, ...) { return otCliOutputFormat(); }
void OpenThreadClass::OpenThreadCliClass::PlatLogv(otLogLevel a, otLogRegion b, const char* c, va_list d) { return otCliPlatLogv(a,b,c,d); }
void OpenThreadClass::OpenThreadCliClass::SetUserCommands(const otCliCommand* a, uint8_t b) { return otCliSetUserCommands(a, b); }
OT_DECL_VFUNC(0, Cli, void, UartInit)
const char* OpenThreadClass::OpenThreadCoapClass::MessageCodeToString(const otMessage* a) { return otCoapMessageCodeToString(a); }
const otCoapOption* OpenThreadClass::OpenThreadCoapClass::OptionIteratorGetFirstOption(otCoapOptionIterator* a) { return otCoapOptionIteratorGetFirstOption(a); }
const otCoapOption* OpenThreadClass::OpenThreadCoapClass::OptionIteratorGetFirstOptionMatching(otCoapOptionIterator* a, uint16_t b) { return otCoapOptionIteratorGetFirstOptionMatching(a,b); }
const otCoapOption* OpenThreadClass::OpenThreadCoapClass::OptionIteratorGetNextOption(otCoapOptionIterator* a) { return otCoapOptionIteratorGetNextOption(a); }
const otCoapOption* OpenThreadClass::OpenThreadCoapClass::OptionIteratorGetNextOptionMatching(otCoapOptionIterator* a, uint16_t b) { return otCoapOptionIteratorGetNextOptionMatching(a, b); }
const uint8_t* OpenThreadClass::OpenThreadCoapClass::MessageGetToken(const otMessage* a) { return otCoapMessageGetToken(a); }
otCoapCode OpenThreadClass::OpenThreadCoapClass::MessageGetCode(const otMessage* a) { return otCoapMessageGetCode(a); }
otCoapType OpenThreadClass::OpenThreadCoapClass::MessageGetType(const otMessage* a) { return otCoapMessageGetType(a); }
OT_DECL__FUNC(1, Coap, otError, AddResource, otCoapResource*)
otError OpenThreadClass::OpenThreadCoapClass::MessageAppendBlock1Option(otMessage* a, uint32_t b, bool c, otCoapBlockSize d) { return otCoapMessageAppendBlock1Option(a,b,c,d); }
otError OpenThreadClass::OpenThreadCoapClass::MessageAppendBlock2Option(otMessage* a, uint32_t b, bool c, otCoapBlockSize d) { return otCoapMessageAppendBlock2Option(a,b,c,d); }
otError OpenThreadClass::OpenThreadCoapClass::MessageAppendContentFormatOption(otMessage* a, otCoapOptionContentFormat b) { return otCoapMessageAppendContentFormatOption(a,b); }
otError OpenThreadClass::OpenThreadCoapClass::MessageAppendMaxAgeOption(otMessage* a, uint32_t b) { return otCoapMessageAppendMaxAgeOption(a,b); }
otError OpenThreadClass::OpenThreadCoapClass::MessageAppendObserveOption(otMessage* a, uint32_t b) { return otCoapMessageAppendObserveOption(a,b); }
otError OpenThreadClass::OpenThreadCoapClass::MessageAppendOption(otMessage* a, uint16_t b, uint16_t c, const void* d) { return otCoapMessageAppendOption(a,b,c,d); }
otError OpenThreadClass::OpenThreadCoapClass::MessageAppendProxyUriOption(otMessage* a, const char* b) { return otCoapMessageAppendProxyUriOption(a,b); }
otError OpenThreadClass::OpenThreadCoapClass::MessageAppendUintOption(otMessage* a, uint16_t b, uint32_t c) { return otCoapMessageAppendUintOption(a,b,c); }
otError OpenThreadClass::OpenThreadCoapClass::MessageAppendUriPathOptions(otMessage* a, const char* b) { return otCoapMessageAppendUriPathOptions(a,b); }
otError OpenThreadClass::OpenThreadCoapClass::MessageAppendUriQueryOption(otMessage* a, const char* b) { return otCoapMessageAppendUriQueryOption(a,b); }
otError OpenThreadClass::OpenThreadCoapClass::MessageInitResponse(otMessage* a, const otMessage* b, otCoapType c, otCoapCode d) { return otCoapMessageInitResponse(a,b,c,d); }
otError OpenThreadClass::OpenThreadCoapClass::MessageSetPayloadMarker(otMessage* a) { return otCoapMessageSetPayloadMarker(a); }
otError OpenThreadClass::OpenThreadCoapClass::MessageSetToken(otMessage* a, const uint8_t* b, uint8_t c) { return otCoapMessageSetToken(a,b,c); }
otError OpenThreadClass::OpenThreadCoapClass::OptionIteratorGetOptionUintValue(otCoapOptionIterator* a, uint64_t* b) { return otCoapOptionIteratorGetOptionUintValue(a,b); }
otError OpenThreadClass::OpenThreadCoapClass::OptionIteratorGetOptionValue(otCoapOptionIterator* a, void* b) { return otCoapOptionIteratorGetOptionValue(a,b); }
otError OpenThreadClass::OpenThreadCoapClass::OptionIteratorInit(otCoapOptionIterator* a, const otMessage* b) { return otCoapOptionIteratorInit(a,b); }
OT_DECL__FUNC(5, Coap, otError, SendRequestWithParameters, otMessage*, const otMessageInfo*, otCoapResponseHandler, void*, const otCoapTxParameters*)
OT_DECL__FUNC(3, Coap, otError, SendResponseWithParameters, otMessage*, const otMessageInfo*, const otCoapTxParameters*)
OT_DECL__FUNC(1, Coap, otError, Start, uint16_t)
OT_DECL__FUNC(0, Coap, otError, Stop)
OT_DECL__FUNC(1, Coap, otMessage*, NewMessage, const otMessageSettings*)
OT_DECL__FUNC(4, Coap, otError, SendRequest, otMessage*, const otMessageInfo*, otCoapResponseHandler, void*)
OT_DECL__FUNC(2, Coap, otError, SendResponse, otMessage*, const otMessageInfo*)
uint16_t OpenThreadClass::OpenThreadCoapClass::BlockSizeFromExponent(otCoapBlockSize a) { return otCoapBlockSizeFromExponent(a); }
uint16_t OpenThreadClass::OpenThreadCoapClass::MessageGetMessageId(const otMessage* a) { return otCoapMessageGetMessageId(a); }
uint8_t OpenThreadClass::OpenThreadCoapClass::MessageGetTokenLength(const otMessage* a) { return otCoapMessageGetTokenLength(a); }
void OpenThreadClass::OpenThreadCoapClass::MessageGenerateToken(otMessage* a, uint8_t b) { return otCoapMessageGenerateToken(a,b); }
void OpenThreadClass::OpenThreadCoapClass::MessageInit(otMessage* a, otCoapType b, otCoapCode c) { return otCoapMessageInit(a,b,c); }
OT_DECL_VFUNC(1, Coap, void, RemoveResource, otCoapResource*)
OT_DECL_VFUNC(2, Coap, void, SetDefaultHandler, otCoapRequestHandler, void*)
OT_DECL__FUNC(0, CoapSecure, bool, IsConnected)
OT_DECL__FUNC(0, CoapSecure, bool, IsConnectionActive)
OT_DECL__FUNC(1, CoapSecure, otError, AddResource, otCoapResource*)
OT_DECL__FUNC(3, CoapSecure, otError, Connect, const otSockAddr*, otHandleCoapSecureClientConnect, void*)
OT_DECL__FUNC(3, CoapSecure, otError, GetPeerCertificateBase64, unsigned char*, size_t*, size_t)
OT_DECL__FUNC(3, CoapSecure, otError, SendRequest, otMessage*, otCoapResponseHandler, void*)
OT_DECL__FUNC(2, CoapSecure, otError, SendResponse, otMessage*, const otMessageInfo*)
OT_DECL__FUNC(1, CoapSecure, otError, Start, uint16_t)
OT_DECL_VFUNC(0, CoapSecure, void, Disconnect)
OT_DECL_VFUNC(1, CoapSecure, void, RemoveResource, otCoapResource*)
OT_DECL_VFUNC(2, CoapSecure, void, SetCaCertificateChain, const uint8_t*, uint32_t)
OT_DECL_VFUNC(4, CoapSecure, void, SetCertificate, const uint8_t*, uint32_t, const uint8_t*, uint32_t)
OT_DECL_VFUNC(2, CoapSecure, void, SetClientConnectedCallback, otHandleCoapSecureClientConnect, void*)
OT_DECL_VFUNC(2, CoapSecure, void, SetDefaultHandler, otCoapRequestHandler, void*)
OT_DECL_VFUNC(4, CoapSecure, void, SetPsk, const uint8_t*, uint16_t, const uint8_t*, uint16_t)
OT_DECL_VFUNC(1, CoapSecure, void, SetSslAuthMode, bool)
OT_DECL_VFUNC(0, CoapSecure, void, Stop)
OT_DECL__FUNC(0, Commissioner, const char*, GetProvisioningUrl)
OT_DECL__FUNC(0, Commissioner, otCommissionerState, GetState)
OT_DECL__FUNC(3, Commissioner, otError, AddJoiner, const otExtAddress*, const char*, uint32_t)
OT_DECL__FUNC(4, Commissioner, otError, AnnounceBegin, uint32_t, uint8_t, uint16_t, const otIp6Address*)
OT_DECL__FUNC(7, Commissioner, otError, EnergyScan, uint32_t, uint8_t, uint16_t, uint16_t, const otIp6Address*, otCommissionerEnergyReportCallback, void*)
OT_DECL__FUNC(2, Commissioner, otError, GetNextJoinerInfo, uint16_t*, otJoinerInfo*)
OT_DECL__FUNC(5, Commissioner, otError, PanIdQuery, uint16_t, uint32_t, const otIp6Address*, otCommissionerPanIdConflictCallback, void*)
OT_DECL__FUNC(1, Commissioner, otError, RemoveJoiner, const otExtAddress*)
OT_DECL__FUNC(2, Commissioner, otError, SendMgmtGet, const uint8_t*, uint8_t)
OT_DECL__FUNC(3, Commissioner, otError, SendMgmtSet, const otCommissioningDataset*, const uint8_t*, uint8_t)
OT_DECL__FUNC(1, Commissioner, otError, SetProvisioningUrl, const char*)
OT_DECL__FUNC(3, Commissioner, otError, Start, otCommissionerStateCallback, otCommissionerJoinerCallback, void*)
OT_DECL__FUNC(0, Commissioner, otError, Stop)
OT_DECL__FUNC(0, Commissioner, uint16_t, GetSessionId)
otError OpenThreadClass::OpenThreadCryptoClass::EcdsaSign(uint8_t* a, uint16_t* b, const uint8_t* c, uint16_t d, const uint8_t* e, uint16_t f) { return otCryptoEcdsaSign(a,b,c,d,e,f); }
void OpenThreadClass::OpenThreadCryptoClass::AesCcm(const uint8_t* a, uint16_t b, uint8_t c, const void* d, uint8_t e, const void* f, uint32_t g, void* h, void* i, uint32_t j, bool k, void* l) { otCryptoAesCcm(a,b,c,d,e,f,g,h,i,j,k,l); }
void OpenThreadClass::OpenThreadCryptoClass::HmacSha256(const uint8_t* a, uint16_t b, const uint8_t* c, uint16_t d, uint8_t* e) { return otCryptoHmacSha256(a,b,c,d,e); }
OT_DECL__FUNC(0, Dataset, bool, IsCommissioned)
otError OpenThreadClass::OpenThreadDatasetClass::GeneratePskc(const char* a, const otNetworkName* b, const otExtendedPanId* c, otPskc* d) { return otDatasetGeneratePskc(a,b,c,d); }
OT_DECL__FUNC(1, Dataset, otError, GetActive, otOperationalDataset*)
OT_DECL__FUNC(1, Dataset, otError, GetPending, otOperationalDataset*)
OT_DECL__FUNC(4, Dataset, otError, SendMgmtActiveGet, const otOperationalDatasetComponents*, const uint8_t*, uint8_t, const otIp6Address*)
OT_DECL__FUNC(3, Dataset, otError, SendMgmtActiveSet, const otOperationalDataset*, const uint8_t*, uint8_t)
OT_DECL__FUNC(4, Dataset, otError, SendMgmtPendingGet, const otOperationalDatasetComponents*, const uint8_t*, uint8_t, const otIp6Address*)
OT_DECL__FUNC(3, Dataset, otError, SendMgmtPendingSet, const otOperationalDataset*, const uint8_t*, uint8_t)
OT_DECL__FUNC(1, Dataset, otError, SetActive, const otOperationalDataset*)
OT_DECL__FUNC(1, Dataset, otError, SetPending, const otOperationalDataset*)
OT_DECL__FUNC(1, Dataset, otError, CreateNewNetwork, otOperationalDataset*)
OT_DECL__FUNC(1, Dataset, otError, SetDelayTimerMinimal, uint32_t)
OT_DECL__FUNC(0, Dataset, uint32_t, GetDelayTimerMinimal)
OT_DECL__FUNC(0, Diag, bool, IsEnabled)
OT_DECL__FUNC(4, Diag, otError, ProcessCmd, uint8_t, char**, char*, size_t)
OT_DECL_VFUNC(3, Diag, void, ProcessCmdLine, const char*, char*, size_t)
OT_DECL__FUNC(3, DnsClient, otError, Query, const otDnsQuery*, otDnsResponseHandler, void*)
mbedtls_entropy_context* OpenThreadClass::OpenThreadEntropyClass::MbedTlsContextGet() { return otEntropyMbedTlsContextGet(); }
const char* OpenThreadClass::OpenThreadThreadClass::ErrorToString(otError a) { return otThreadErrorToString(a); }
void OpenThreadClass::OpenThreadHeapClass::Free(void* a) { return otHeapFree(a); }
void OpenThreadClass::OpenThreadHeapClass::SetCAllocFree(otHeapCAllocFn a, otHeapFreeFn b) { return otHeapSetCAllocFree(a,b); }
void* OpenThreadClass::OpenThreadHeapClass::CAlloc(size_t a, size_t b) { return otHeapCAlloc(a,b); }
OT_DECL__FUNC(1, Icmp6, otError, RegisterHandler, otIcmp6Handler*)
OT_DECL__FUNC(3, Icmp6, otError, SendEchoRequest, otMessage*, const otMessageInfo*, uint16_t)
OT_DECL__FUNC(0, Icmp6, otIcmp6EchoMode, GetEchoMode)
OT_DECL_VFUNC(1, Icmp6, void, SetEchoMode, otIcmp6EchoMode)
OT_DECL__FUNC(0, Instance, bool, IsInitialized)
OT_DECL__FUNC(0, Instance, otError, ErasePersistentInfo)
otInstance* OpenThreadClass::OpenThreadInstanceClass::Init(void* a, size_t* b) { return otInstanceInit(a,b); }
otInstance* OpenThreadClass::OpenThreadInstanceClass::InitSingle() { return otInstanceInitSingle(); }
OT_DECL_VFUNC(0, Instance, void, FactoryReset)
OT_DECL_VFUNC(0, Instance, void, Finalize)
OT_DECL_VFUNC(0, Instance, void, Reset)
bool OpenThreadClass::OpenThreadIp6Class::IsAddressEqual(const otIp6Address* a, const otIp6Address* b) { return otIp6IsAddressEqual(a,b); }
bool OpenThreadClass::OpenThreadIp6Class::IsAddressUnspecified(const otIp6Address* a) { return otIp6IsAddressUnspecified(a); }
OT_DECL__FUNC(0, Ip6, bool, IsEnabled)
OT_DECL__FUNC(0, Ip6, bool, IsMulticastPromiscuousEnabled)
OT_DECL__FUNC(0, Ip6, bool, IsReceiveFilterEnabled)
OT_DECL__FUNC(0, Ip6, bool, IsSlaacEnabled)
OT_DECL__FUNC(0, Ip6, const otNetifAddress*, GetUnicastAddresses)
OT_DECL__FUNC(0, Ip6, const otNetifMulticastAddress*, GetMulticastAddresses)
OT_DECL__FUNC(1, Ip6, const uint16_t*, GetUnsecurePorts, uint8_t*)
OT_DECL__FUNC(1, Ip6, otError, AddUnicastAddress, const otNetifAddress*)
OT_DECL__FUNC(1, Ip6, otError, AddUnsecurePort, uint16_t)
otError OpenThreadClass::OpenThreadIp6Class::AddressFromString(const char* a, otIp6Address* b) { return otIp6AddressFromString(a,b); }
OT_DECL__FUNC(1, Ip6, otError, RemoveUnicastAddress, const otIp6Address*)
OT_DECL__FUNC(1, Ip6, otError, RemoveUnsecurePort, uint16_t)
OT_DECL__FUNC(1, Ip6, otError, SelectSourceAddress, otMessageInfo*)
OT_DECL__FUNC(1, Ip6, otError, Send, otMessage*)
OT_DECL__FUNC(1, Ip6, otError, SetEnabled, bool)
OT_DECL__FUNC(1, Ip6, otError, SubscribeMulticastAddress, const otIp6Address*)
OT_DECL__FUNC(1, Ip6, otError, UnsubscribeMulticastAddress, const otIp6Address*)
OT_DECL__FUNC(1, Ip6, otMessage*, NewMessage, const otMessageSettings*)
OT_DECL__FUNC(3, Ip6, otMessage*, NewMessageFromBuffer, const uint8_t*, uint16_t, const otMessageSettings*)
uint8_t OpenThreadClass::OpenThreadIp6Class::PrefixMatch(const otIp6Address* a, const otIp6Address* b) { return otIp6PrefixMatch(a,b); }
OT_DECL_VFUNC(0, Ip6, void, RemoveAllUnsecurePorts)
OT_DECL_VFUNC(2, Ip6, void, SetAddressCallback, otIp6AddressCallback, void*)
OT_DECL_VFUNC(1, Ip6, void, SetMulticastPromiscuousEnabled, bool)
OT_DECL_VFUNC(2, Ip6, void, SetReceiveCallback, otIp6ReceiveCallback, void*)
OT_DECL_VFUNC(1, Ip6, void, SetReceiveFilterEnabled, bool)
OT_DECL_VFUNC(1, Ip6, void, SetSlaacEnabled, bool)
OT_DECL_VFUNC(1, Ip6, void, SetSlaacPrefixFilter, otIp6SlaacPrefixFilter)
OT_DECL__FUNC(0, JamDetection, bool, GetState)
OT_DECL__FUNC(0, JamDetection, bool, IsEnabled)
OT_DECL__FUNC(0, JamDetection, int8_t, GetRssiThreshold)
OT_DECL__FUNC(1, JamDetection, otError, SetBusyPeriod, uint8_t)
OT_DECL__FUNC(1, JamDetection, otError, SetRssiThreshold, int8_t)
OT_DECL__FUNC(1, JamDetection, otError, SetWindow, uint8_t)
OT_DECL__FUNC(2, JamDetection, otError, Start, otJamDetectionCallback, void*)
OT_DECL__FUNC(0, JamDetection, otError, Stop)
OT_DECL__FUNC(0, JamDetection, uint64_t, GetHistoryBitmap)
OT_DECL__FUNC(0, JamDetection, uint8_t, GetBusyPeriod)
OT_DECL__FUNC(0, JamDetection, uint8_t, GetWindow)
OT_DECL__FUNC(8, Joiner, otError, Start, const char*, const char*, const char*, const char*, const char*, const char*, otJoinerCallback, void*)
OT_DECL__FUNC(0, Joiner, otJoinerState, GetState)
OT_DECL_VFUNC(1, Joiner, void, GetId, otExtAddress*)
OT_DECL_VFUNC(0, Joiner, void, Stop)
OT_DECL__FUNC(0, Link, bool, IsActiveScanInProgress)
OT_DECL__FUNC(0, Link, bool, IsEnabled)
OT_DECL__FUNC(0, Link, bool, IsEnergyScanInProgress)
OT_DECL__FUNC(0, Link, bool, IsInTransmitState)
OT_DECL__FUNC(0, Link, bool, IsPromiscuous)
OT_DECL__FUNC(0, Link, const otExtAddress*, GetExtendedAddress)
OT_DECL__FUNC(0, Link, const otMacCounters*, GetCounters)
OT_DECL__FUNC(1, Link, const uint32_t*, GetTxDirectRetrySuccessHistogram, uint8_t*)
OT_DECL__FUNC(1, Link, const uint32_t*, GetTxIndirectRetrySuccessHistogram, uint8_t*)
OT_DECL__FUNC(1, Link, int8_t, ConvertLinkQualityToRss, uint8_t)
OT_DECL__FUNC(4, Link, otError, ActiveScan, uint32_t, uint16_t, otHandleActiveScanResult, void*)
OT_DECL__FUNC(4, Link, otError, EnergyScan, uint32_t, uint16_t, otHandleEnergyScanResult, void*)
OT_DECL__FUNC(1, Link, otError, FilterAddAddress, const otExtAddress*)
OT_DECL__FUNC(2, Link, otError, FilterAddRssIn, const otExtAddress*, int8_t)
OT_DECL__FUNC(2, Link, otError, FilterGetNextAddress, otMacFilterIterator*, otMacFilterEntry*)
OT_DECL__FUNC(2, Link, otError, FilterGetNextRssIn, otMacFilterIterator*, otMacFilterEntry*)
OT_DECL__FUNC(1, Link, otError, FilterRemoveAddress, const otExtAddress*)
OT_DECL__FUNC(1, Link, otError, FilterRemoveRssIn, const otExtAddress*)
OT_DECL__FUNC(1, Link, otError, FilterSetAddressMode, otMacFilterAddressMode)
OT_DECL__FUNC(1, Link, otError, OutOfBandTransmitRequest, otRadioFrame*)
OT_DECL__FUNC(0, Link, otError, SendDataRequest)
OT_DECL__FUNC(1, Link, otError, SetChannel, uint8_t)
OT_DECL__FUNC(1, Link, otError, SetEnabled, bool)
OT_DECL__FUNC(1, Link, otError, SetExtendedAddress, const otExtAddress*)
OT_DECL__FUNC(1, Link, otError, SetPanId, otPanId)
OT_DECL__FUNC(1, Link, otError, SetPollPeriod, uint32_t)
OT_DECL__FUNC(1, Link, otError, SetPromiscuous, bool)
OT_DECL__FUNC(1, Link, otError, SetSupportedChannelMask, uint32_t)
OT_DECL__FUNC(0, Link, otMacFilterAddressMode, FilterGetAddressMode)
OT_DECL__FUNC(0, Link, otPanId, GetPanId)
OT_DECL__FUNC(0, Link, otShortAddress, GetShortAddress)
OT_DECL__FUNC(0, Link, uint16_t, GetCcaFailureRate)
OT_DECL__FUNC(0, Link, uint32_t, GetPollPeriod)
OT_DECL__FUNC(0, Link, uint32_t, GetSupportedChannelMask)
OT_DECL__FUNC(1, Link, uint8_t, ConvertRssToLinkQuality, int8_t)
OT_DECL__FUNC(0, Link, uint8_t, GetChannel)
OT_DECL__FUNC(0, Link, uint8_t, GetMaxFrameRetriesDirect)
OT_DECL__FUNC(0, Link, uint8_t, GetMaxFrameRetriesIndirect)
OT_DECL_VFUNC(0, Link, void, FilterClearAddresses)
OT_DECL_VFUNC(0, Link, void, FilterClearRssIn)
OT_DECL_VFUNC(1, Link, void, GetFactoryAssignedIeeeEui64, otExtAddress*)
OT_DECL_VFUNC(0, Link, void, ResetCounters)
OT_DECL_VFUNC(0, Link, void, ResetTxRetrySuccessHistogram)
OT_DECL_VFUNC(1, Link, void, SetMaxFrameRetriesDirect, uint8_t)
OT_DECL_VFUNC(1, Link, void, SetMaxFrameRetriesIndirect, uint8_t)
OT_DECL_VFUNC(2, Link, void, SetPcapCallback, otLinkPcapCallback, void*)
OT_DECL__FUNC(0, Link, bool, RawGetPromiscuous)
OT_DECL__FUNC(0, Link, bool, RawIsEnabled)
OT_DECL__FUNC(0, Link, int8_t, RawGetRssi)
OT_DECL__FUNC(3, Link, otError, RawEnergyScan, uint8_t, uint16_t, otLinkRawEnergyScanDone)
OT_DECL__FUNC(1, Link, otError, RawReceive, otLinkRawReceiveDone)
OT_DECL__FUNC(1, Link, otError, RawSetEnable, bool)
OT_DECL__FUNC(1, Link, otError, RawSetPromiscuous, bool)
OT_DECL__FUNC(1, Link, otError, RawSetShortAddress, uint16_t)
OT_DECL__FUNC(0, Link, otError, RawSleep)
OT_DECL__FUNC(1, Link, otError, RawSrcMatchAddExtEntry, const otExtAddress*)
OT_DECL__FUNC(1, Link, otError, RawSrcMatchAddShortEntry, uint16_t)
OT_DECL__FUNC(0, Link, otError, RawSrcMatchClearExtEntries)
OT_DECL__FUNC(1, Link, otError, RawSrcMatchClearExtEntry, const otExtAddress*)
OT_DECL__FUNC(0, Link, otError, RawSrcMatchClearShortEntries)
OT_DECL__FUNC(1, Link, otError, RawSrcMatchClearShortEntry, uint16_t)
OT_DECL__FUNC(1, Link, otError, RawSrcMatchEnable, bool)
OT_DECL__FUNC(1, Link, otError, RawTransmit, otLinkRawTransmitDone)
OT_DECL__FUNC(0, Link, otRadioCaps, RawGetCaps)
OT_DECL__FUNC(0, Link, otRadioFrame*, RawGetTransmitBuffer)
otLogLevel OpenThreadClass::OpenThreadLoggingClass::GetLevel() { return otLoggingGetLevel(); }
void OpenThreadClass::OpenThreadLoggingClass::SetLevel(otLogLevel a) { return otLoggingSetLevel(a); }
bool OpenThreadClass::OpenThreadMessageClass::IsLinkSecurityEnabled(const otMessage* a) { return otMessageIsLinkSecurityEnabled(a); }
int OpenThreadClass::OpenThreadMessageClass::Write(otMessage* a, uint16_t b, const void* c, uint16_t d) { return otMessageWrite(a,b,c,d); }
int8_t OpenThreadClass::OpenThreadMessageClass::GetRss(const otMessage* a) { return otMessageGetRss(a); }
otError OpenThreadClass::OpenThreadMessageClass::Append(otMessage* a, const void* b, uint16_t c) { return otMessageAppend(a,b,c); }
otError OpenThreadClass::OpenThreadMessageClass::QueueDequeue(otMessageQueue* a, otMessage* b) { return otMessageQueueDequeue(a,b); }
otError OpenThreadClass::OpenThreadMessageClass::QueueEnqueue(otMessageQueue* a, otMessage* b) { return otMessageQueueEnqueue(a,b); }
otError OpenThreadClass::OpenThreadMessageClass::QueueEnqueueAtHead(otMessageQueue* a, otMessage* b) { return otMessageQueueEnqueueAtHead(a,b); }
otError OpenThreadClass::OpenThreadMessageClass::SetLength(otMessage* a, uint16_t b) { return otMessageSetLength(a,b); }
otError OpenThreadClass::OpenThreadMessageClass::SetOffset(otMessage* a, uint16_t b) { return otMessageSetOffset(a,b); }
otMessage* OpenThreadClass::OpenThreadMessageClass::QueueGetHead(otMessageQueue* a) { return otMessageQueueGetHead(a); }
otMessage* OpenThreadClass::OpenThreadMessageClass::QueueGetNext(otMessageQueue* a, const otMessage* b) { return otMessageQueueGetNext(a,b); }
uint16_t OpenThreadClass::OpenThreadMessageClass::GetLength(const otMessage* a) { return otMessageGetLength(a); }
uint16_t OpenThreadClass::OpenThreadMessageClass::GetOffset(const otMessage* a) { return otMessageGetOffset(a); }
uint16_t OpenThreadClass::OpenThreadMessageClass::Read(const otMessage* a, uint16_t b, void* c, uint16_t d) { return otMessageRead(a,b,c,d); }
void OpenThreadClass::OpenThreadMessageClass::Free(otMessage* a) { return otMessageFree(a); }
OT_DECL_VFUNC(1, Message, void, GetBufferInfo, otBufferInfo*)
void OpenThreadClass::OpenThreadMessageClass::QueueInit(otMessageQueue* a) { return otMessageQueueInit(a); }
void OpenThreadClass::OpenThreadMessageClass::SetDirectTransmission(otMessage* a, bool b) { return otMessageSetDirectTransmission(a,b); }
otError OpenThreadClass::OpenThreadNcpClass::StreamWrite(int a, const uint8_t* b, int c) { return otNcpStreamWrite(a,b,c); }
void OpenThreadClass::OpenThreadNcpClass::HandleDidReceiveNewLegacyUlaPrefix(const uint8_t* a) { return otNcpHandleDidReceiveNewLegacyUlaPrefix(a); }
void OpenThreadClass::OpenThreadNcpClass::HandleLegacyNodeDidJoin(const otExtAddress* a) { return otNcpHandleLegacyNodeDidJoin(a); }
OT_DECL_VFUNC(0, Ncp, void, Init)
void OpenThreadClass::OpenThreadNcpClass::PlatLogv(otLogLevel a, otLogRegion b, const char* c, va_list d) { return otNcpPlatLogv(a,b,c,d); }
void OpenThreadClass::OpenThreadNcpClass::RegisterLegacyHandlers(const otNcpLegacyHandlers* a) { return otNcpRegisterLegacyHandlers(a); }
void OpenThreadClass::OpenThreadNcpClass::RegisterPeekPokeDelagates(otNcpDelegateAllowPeekPoke a, otNcpDelegateAllowPeekPoke b) { return otNcpRegisterPeekPokeDelagates(a,b); }
OT_DECL__FUNC(3, NetData, otError, Get, bool, uint8_t*, uint8_t*)
OT_DECL__FUNC(2, NetData, otError, GetNextOnMeshPrefix, otNetworkDataIterator*, otBorderRouterConfig*)
OT_DECL__FUNC(2, NetData, otError, GetNextRoute, otNetworkDataIterator*, otExternalRouteConfig*)
OT_DECL__FUNC(2, NetData, otError, GetNextService, otNetworkDataIterator*, otServiceConfig*)
OT_DECL__FUNC(0, NetData, uint8_t, GetStableVersion)
OT_DECL__FUNC(0, NetData, uint8_t, GetVersion)
otError OpenThreadClass::OpenThreadThreadClass::GetNextDiagnosticTlv(const otMessage* a, otNetworkDiagIterator* b, otNetworkDiagTlv* c) { return otThreadGetNextDiagnosticTlv(a,b,c); }
OT_DECL__FUNC(3, Thread, otError, SendDiagnosticGet, const otIp6Address*, const uint8_t*, uint8_t)
OT_DECL__FUNC(3, Thread, otError, SendDiagnosticReset, const otIp6Address*, const uint8_t*, uint8_t)
OT_DECL_VFUNC(2, Thread, void, SetReceiveDiagnosticGetCallback, otReceiveDiagnosticGetCallback, void*)
OT_DECL__FUNC(1, NetworkTime, otError, SetSyncPeriod, uint16_t)
OT_DECL__FUNC(1, NetworkTime, otError, SetXtalThreshold, uint16_t)
OT_DECL__FUNC(1, NetworkTime, otNetworkTimeStatus, Get, uint64_t*)
OT_DECL__FUNC(0, NetworkTime, uint16_t, GetSyncPeriod)
OT_DECL__FUNC(0, NetworkTime, uint16_t, GetXtalThreshold)
OT_DECL_VFUNC(2, NetworkTime, void, SyncSetCallback, otNetworkTimeSyncCallbackFn, void*)
bool OpenThreadClass::OpenThreadPlatClass::DiagModeGet() { return otPlatDiagModeGet(); }
OT_DECL__FUNC(4, Plat, otError, DiagProcess, uint8_t, char**, char*, size_t)
OT_DECL_VFUNC(0, Plat, void, DiagAlarmCallback)
void OpenThreadClass::OpenThreadPlatClass::DiagChannelSet(uint8_t a) { return otPlatDiagChannelSet(a); }
void OpenThreadClass::OpenThreadPlatClass::DiagModeSet(bool a) { return otPlatDiagModeSet(a); }
OT_DECL_VFUNC(2, Plat, void, DiagRadioReceived, otRadioFrame*, otError)
void OpenThreadClass::OpenThreadPlatClass::DiagTxPowerSet(int8_t a) { return otPlatDiagTxPowerSet(a); }
otError OpenThreadClass::OpenThreadPlatClass::EntropyGet(uint8_t* a, uint16_t b) { return otPlatEntropyGet(a,b); }
//void OpenThreadClass::OpenThreadPlatClass::Log(otLogLevel, otLogRegion, const char*, ...) { return otPlatLog(); }
otError OpenThreadClass::OpenThreadPlatClass::UdpBind(otUdpSocket* a) { OT_API_CALL_RET(otError, otPlatUdpBind(a);); }
otError OpenThreadClass::OpenThreadPlatClass::UdpClose(otUdpSocket* a) { OT_API_CALL_RET(otError, otPlatUdpClose(a);); }
otError OpenThreadClass::OpenThreadPlatClass::UdpConnect(otUdpSocket* a) { OT_API_CALL_RET(otError, otPlatUdpConnect(a);); }
otError OpenThreadClass::OpenThreadPlatClass::UdpSend(otUdpSocket* a, otMessage* b, const otMessageInfo* c) { OT_API_CALL_RET(otError, otPlatUdpSend(a,b,c);); }
otError OpenThreadClass::OpenThreadPlatClass::UdpSocket(otUdpSocket* a) { OT_API_CALL_RET(otError, otPlatUdpSocket(a);); }
mbedtls_ctr_drbg_context* OpenThreadClass::OpenThreadRandomCryptoClass::MbedTlsContextGet() { return otRandomCryptoMbedTlsContextGet(); }
otError OpenThreadClass::OpenThreadRandomCryptoClass::FillBuffer(uint8_t* a, uint16_t b) { return otRandomCryptoFillBuffer(a,b); }
uint16_t OpenThreadClass::OpenThreadRandomNonCryptoClass::GetUint16() { return otRandomNonCryptoGetUint16(); }
uint16_t OpenThreadClass::OpenThreadRandomNonCryptoClass::GetUint16InRange(uint16_t a, uint16_t b) { return otRandomNonCryptoGetUint16InRange(a,b); }
uint32_t OpenThreadClass::OpenThreadRandomNonCryptoClass::AddJitter(uint32_t a, uint16_t b) { return otRandomNonCryptoAddJitter(a,b); }
uint32_t OpenThreadClass::OpenThreadRandomNonCryptoClass::GetUint32() { return otRandomNonCryptoGetUint32(); }
uint32_t OpenThreadClass::OpenThreadRandomNonCryptoClass::GetUint32InRange(uint32_t a, uint32_t b) { return otRandomNonCryptoGetUint32InRange(a,b); }
uint8_t OpenThreadClass::OpenThreadRandomNonCryptoClass::GetUint8() { return otRandomNonCryptoGetUint8(); }
uint8_t OpenThreadClass::OpenThreadRandomNonCryptoClass::GetUint8InRange(uint8_t a, uint8_t b) { return otRandomNonCryptoGetUint8InRange(a,b); }
void OpenThreadClass::OpenThreadRandomNonCryptoClass::FillBuffer(uint8_t* a, uint16_t b) { return otRandomNonCryptoFillBuffer(a,b); }
OT_DECL__FUNC(1, Server, otError, AddService, const otServiceConfig*)
OT_DECL__FUNC(3, Server, otError, GetNetDataLocal, bool, uint8_t*, uint8_t*)
OT_DECL__FUNC(2, Server, otError, GetNextService, otNetworkDataIterator*, otServiceConfig*)
OT_DECL__FUNC(0, Server, otError, Register)
OT_DECL__FUNC(3, Server, otError, RemoveService, uint32_t, const uint8_t*, uint8_t)
OT_DECL__FUNC(3, SntpClient, otError, Query, const otSntpQuery*, otSntpResponseHandler, void*)
OT_DECL_VFUNC(1, SntpClient, void, SetUnixEra, uint32_t)
OT_DECL__FUNC(0, Tasklets, bool, ArePending)
OT_DECL_VFUNC(0, Tasklets, void, Process)
OT_DECL_VFUNC(0, Tasklets, void, SignalPending)
OT_DECL__FUNC(0, Thread, bool, IsDiscoverInProgress)
OT_DECL__FUNC(0, Thread, bool, IsSingleton)
OT_DECL__FUNC(0, Thread, const char*, GetNetworkName)
OT_DECL__FUNC(0, Thread, const otExtendedPanId*, GetExtendedPanId)
OT_DECL__FUNC(0, Thread, const otIp6Address*, GetLinkLocalIp6Address)
OT_DECL__FUNC(0, Thread, const otIp6Address*, GetMeshLocalEid)
OT_DECL__FUNC(0, Thread, const otIp6Address*, GetRloc)
OT_DECL__FUNC(0, Thread, const otIpCounters*, GetIp6Counters)
OT_DECL__FUNC(0, Thread, const otMasterKey*, GetMasterKey)
OT_DECL__FUNC(0, Thread, const otMeshLocalPrefix*, GetMeshLocalPrefix)
OT_DECL__FUNC(0, Thread, const otMleCounters*, GetMleCounters)
OT_DECL__FUNC(0, Thread, otDeviceRole, GetDeviceRole)
OT_DECL__FUNC(0, Thread, otError, BecomeChild)
OT_DECL__FUNC(0, Thread, otError, BecomeDetached)
OT_DECL__FUNC(6, Thread, otError, Discover, uint32_t, uint16_t, bool, bool, otHandleActiveScanResult, void*)
OT_DECL__FUNC(1, Thread, otError, GetLeaderData, otLeaderData*)
OT_DECL__FUNC(1, Thread, otError, GetLeaderRloc, otIp6Address*)
OT_DECL__FUNC(2, Thread, otError, GetNextNeighborInfo, otNeighborInfoIterator*, otNeighborInfo*)
OT_DECL__FUNC(1, Thread, otError, GetParentAverageRssi, int8_t*)
OT_DECL__FUNC(1, Thread, otError, GetParentInfo, otRouterInfo*)
OT_DECL__FUNC(1, Thread, otError, GetParentLastRssi, int8_t*)
OT_DECL__FUNC(1, Thread, otError, SetEnabled, bool)
OT_DECL__FUNC(1, Thread, otError, SetExtendedPanId, const otExtendedPanId*)
OT_DECL__FUNC(1, Thread, otError, SetLinkMode, otLinkModeConfig)
OT_DECL__FUNC(1, Thread, otError, SetMasterKey, const otMasterKey*)
OT_DECL__FUNC(1, Thread, otError, SetMeshLocalPrefix, const otMeshLocalPrefix*)
OT_DECL__FUNC(1, Thread, otError, SetNetworkName, const char*)
OT_DECL__FUNC(0, Thread, otLinkModeConfig, GetLinkMode)
OT_DECL__FUNC(0, Thread, uint16_t, GetRloc16)
uint16_t OpenThreadClass::OpenThreadThreadClass::GetVersion() { return otThreadGetVersion(); }
OT_DECL__FUNC(0, Thread, uint32_t, GetChildTimeout)
OT_DECL__FUNC(0, Thread, uint32_t, GetKeySequenceCounter)
OT_DECL__FUNC(0, Thread, uint32_t, GetKeySwitchGuardTime)
OT_DECL__FUNC(0, Thread, uint32_t, GetPartitionId)
OT_DECL__FUNC(0, Thread, uint8_t, GetLeaderRouterId)
OT_DECL__FUNC(0, Thread, uint8_t, GetLeaderWeight)
OT_DECL_VFUNC(2, Thread, void, RegisterParentResponseCallback, otThreadParentResponseCallback, void*)
OT_DECL_VFUNC(0, Thread, void, ResetIp6Counters)
OT_DECL_VFUNC(0, Thread, void, ResetMleCounters)
OT_DECL_VFUNC(1, Thread, void, SetChildTimeout, uint32_t)
OT_DECL_VFUNC(1, Thread, void, SetKeySequenceCounter, uint32_t)
OT_DECL_VFUNC(1, Thread, void, SetKeySwitchGuardTime, uint32_t)
OT_DECL__FUNC(0, Thread, bool, IsRouterEligible)
OT_DECL__FUNC(0, Thread, const otPskc*, GetPskc)
OT_DECL__FUNC(0, Thread, int8_t, GetParentPriority)
OT_DECL__FUNC(0, Thread, otError, BecomeLeader)
OT_DECL__FUNC(0, Thread, otError, BecomeRouter)
OT_DECL__FUNC(2, Thread, otError, GetChildInfoById, uint16_t, otChildInfo*)
OT_DECL__FUNC(2, Thread, otError, GetChildInfoByIndex, uint16_t, otChildInfo*)
OT_DECL__FUNC(3, Thread, otError, GetChildNextIp6Address, uint16_t, otChildIp6AddressIterator*, otIp6Address*)
OT_DECL__FUNC(2, Thread, otError, GetNextCacheEntry, otCacheEntryInfo*, otCacheEntryIterator*)
OT_DECL__FUNC(2, Thread, otError, GetRouterInfo, uint16_t, otRouterInfo*)
OT_DECL__FUNC(1, Thread, otError, ReleaseRouterId, uint8_t)
OT_DECL__FUNC(1, Thread, otError, SetJoinerUdpPort, uint16_t)
OT_DECL__FUNC(1, Thread, otError, SetMaxAllowedChildren, uint16_t)
OT_DECL__FUNC(1, Thread, otError, SetMaxChildIpAddresses, uint8_t)
OT_DECL__FUNC(1, Thread, otError, SetParentPriority, int8_t)
OT_DECL__FUNC(1, Thread, otError, SetPreferredRouterId, uint8_t)
OT_DECL__FUNC(1, Thread, otError, SetPskc, const otPskc*)
OT_DECL__FUNC(1, Thread, otError, SetRouterEligible, bool)
OT_DECL__FUNC(0, Thread, uint16_t, GetJoinerUdpPort)
OT_DECL__FUNC(0, Thread, uint16_t, GetMaxAllowedChildren)
OT_DECL__FUNC(0, Thread, uint32_t, GetContextIdReuseDelay)
OT_DECL__FUNC(0, Thread, uint32_t, GetLocalLeaderPartitionId)
OT_DECL__FUNC(0, Thread, uint8_t, GetLocalLeaderWeight)
OT_DECL__FUNC(0, Thread, uint8_t, GetMaxChildIpAddresses)
OT_DECL__FUNC(0, Thread, uint8_t, GetMaxRouterId)
OT_DECL__FUNC(0, Thread, uint8_t, GetNetworkIdTimeout)
OT_DECL__FUNC(0, Thread, uint8_t, GetRouterDowngradeThreshold)
OT_DECL__FUNC(0, Thread, uint8_t, GetRouterIdSequence)
OT_DECL__FUNC(0, Thread, uint8_t, GetRouterSelectionJitter)
OT_DECL__FUNC(0, Thread, uint8_t, GetRouterUpgradeThreshold)
OT_DECL_VFUNC(1, Thread, void, RegisterNeighborTableCallback, otNeighborTableCallback)
OT_DECL_VFUNC(1, Thread, void, SetContextIdReuseDelay, uint32_t)
OT_DECL_VFUNC(1, Thread, void, SetLocalLeaderPartitionId, uint32_t)
OT_DECL_VFUNC(1, Thread, void, SetLocalLeaderWeight, uint8_t)
OT_DECL_VFUNC(1, Thread, void, SetNetworkIdTimeout, uint8_t)
OT_DECL_VFUNC(1, Thread, void, SetRouterDowngradeThreshold, uint8_t)
OT_DECL_VFUNC(1, Thread, void, SetRouterSelectionJitter, uint8_t)
OT_DECL_VFUNC(1, Thread, void, SetRouterUpgradeThreshold, uint8_t)
OT_DECL_VFUNC(1, Thread, void, SetSteeringData, const otExtAddress*)
OT_DECL__FUNC(1, Udp, otError, AddReceiver, otUdpReceiver*)
otError OpenThreadClass::OpenThreadUdpClass::Bind(otUdpSocket* a, otSockAddr* b) { OT_API_CALL_RET(otError, otUdpBind(a,b); ); }
otError OpenThreadClass::OpenThreadUdpClass::Close(otUdpSocket* a) { OT_API_CALL_RET(otError, otUdpClose(a);); }
otError OpenThreadClass::OpenThreadUdpClass::Connect(otUdpSocket* a, otSockAddr* b) { OT_API_CALL_RET(otError, otUdpConnect(a,b);); }
OT_DECL__FUNC(3, Udp, otError, Open, otUdpSocket*, otUdpReceive, void*)
OT_DECL__FUNC(1, Udp, otError, RemoveReceiver, otUdpReceiver*)
otError OpenThreadClass::OpenThreadUdpClass::Send(otUdpSocket* a, otMessage* b, const otMessageInfo* c) { OT_API_CALL_RET(otError, otUdpSend(a,b,c); ); }
OT_DECL__FUNC(2, Udp, otError, SendDatagram, otMessage*, otMessageInfo*)
OT_DECL__FUNC(1, Udp, otMessage*, NewMessage, const otMessageSettings*)
OT_DECL__FUNC(0, Udp, otUdpSocket*, GetSockets)
OT_DECL_VFUNC(4, Udp, void, ForwardReceive, otMessage*, uint16_t, const otIp6Address*, uint16_t)
OT_DECL_VFUNC(2, Udp, void, ForwardSetForwarder, otUdpForwarder, void*)
