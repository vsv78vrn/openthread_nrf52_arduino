  class OpenThreadBackboneRouterClass {
  friend class OpenThreadClass;
  public:
    otError GetPrimary(otBackboneRouterConfig* aConfig);
    otBackboneRouterState GetState();
    otError Register();
    uint8_t GetRegistrationJitter();
    void GetConfig(otBackboneRouterConfig* aConfig);
    void SetConfig(const otBackboneRouterConfig* aConfig);
    void SetEnabled(bool aEnable);
    void SetRegistrationJitter(uint8_t aJitter);
  };

  class OpenThreadBorderAgentClass {
  friend class OpenThreadClass;
  public:
    otBorderAgentState GetState();
  };

  class OpenThreadBorderRouterClass {
  friend class OpenThreadClass;
  public:
    otError AddOnMeshPrefix(const otBorderRouterConfig* aConfig);
    otError AddRoute(const otExternalRouteConfig* aConfig);
    otError GetNetData(bool aStable, uint8_t* aData, uint8_t* aDataLength);
    otError GetNextOnMeshPrefix(otNetworkDataIterator* aIterator, otBorderRouterConfig* aConfig);
    otError GetNextRoute(otNetworkDataIterator* aIterator, otExternalRouteConfig* aConfig);
    otError Register();
    otError RemoveOnMeshPrefix(const otIp6Prefix* aPrefix);
    otError RemoveRoute(const otIp6Prefix* aPrefix);
  };

  class OpenThreadChannelManagerClass {
  friend class OpenThreadClass;
  public:
    bool GetAutoChannelSelectionEnabled();
    otError RequestChannelSelect(bool aSkipQualityCheck);
    otError SetAutoChannelSelectionInterval(uint32_t aInterval);
    otError SetDelay(uint16_t aDelay);
    uint16_t GetDelay();
    uint32_t GetAutoChannelSelectionInterval();
    uint32_t GetFavoredChannels();
    uint32_t GetSupportedChannels();
    uint8_t GetRequestedChannel();
    void RequestChannelChange(uint8_t aChannel);
    void SetAutoChannelSelectionEnabled(bool aEnabled);
    void SetFavoredChannels(uint32_t aChannelMask);
    void SetSupportedChannels(uint32_t aChannelMask);
  };

  class OpenThreadChannelMonitorClass {
  friend class OpenThreadClass;
  public:
    bool IsEnabled();
    int8_t GetRssiThreshold();
    otError SetEnabled(bool aEnabled);
    uint16_t GetChannelOccupancy(uint8_t aChannel);
    uint32_t GetSampleCount();
    uint32_t GetSampleInterval();
    uint32_t GetSampleWindow();
  };

  class OpenThreadChildSupervisionClass {
  friend class OpenThreadClass;
  public:
    uint16_t GetCheckTimeout();
    uint16_t GetInterval();
    void SetCheckTimeout(uint16_t aTimeout);
    void SetInterval(uint16_t aInterval);
  };

  class OpenThreadCliClass {
  friend class OpenThreadClass;
  public:
    void AppendResult(otError aError);
    void ConsoleInit(otCliConsoleOutputCallback aCallback, void* aContext);
    void ConsoleInputLine(char* aBuf, uint16_t aBufLength);
    void Output(const char* aString, uint16_t aLength);
    void OutputBytes(const uint8_t* aBytes, uint8_t aLength);
    void OutputFormat(const char* aFmt,...);
    void PlatLogv(otLogLevel aLogLevel, otLogRegion aLogRegion, const char* aFormat, va_list aArgs);
    void SetUserCommands(const otCliCommand* aUserCommands, uint8_t aLength);
    void UartInit();
  };

  class OpenThreadCoapClass {
  friend class OpenThreadClass;
  public:
    const char* MessageCodeToString(const otMessage* aMessage);
    const otCoapOption* OptionIteratorGetFirstOption(otCoapOptionIterator* aIterator);
    const otCoapOption* OptionIteratorGetFirstOptionMatching(otCoapOptionIterator* aIterator, uint16_t aOption);
    const otCoapOption* OptionIteratorGetNextOption(otCoapOptionIterator* aIterator);
    const otCoapOption* OptionIteratorGetNextOptionMatching(otCoapOptionIterator* aIterator, uint16_t aOption);
    const uint8_t* MessageGetToken(const otMessage* aMessage);
    otCoapCode MessageGetCode(const otMessage* aMessage);
    otCoapType MessageGetType(const otMessage* aMessage);
    otError AddResource(otCoapResource* aResource);
    otError MessageAppendBlock1Option(otMessage* aMessage, uint32_t aNum, bool aMore, otCoapBlockSize aSize);
    otError MessageAppendBlock2Option(otMessage* aMessage, uint32_t aNum, bool aMore, otCoapBlockSize aSize);
    otError MessageAppendContentFormatOption(otMessage* aMessage, otCoapOptionContentFormat aContentFormat);
    otError MessageAppendMaxAgeOption(otMessage* aMessage, uint32_t aMaxAge);
    otError MessageAppendObserveOption(otMessage* aMessage, uint32_t aObserve);
    otError MessageAppendOption(otMessage* aMessage, uint16_t aNumber, uint16_t aLength, const void* aValue);
    otError MessageAppendProxyUriOption(otMessage* aMessage, const char* aUriPath);
    otError MessageAppendUintOption(otMessage* aMessage, uint16_t aNumber, uint32_t aValue);
    otError MessageAppendUriPathOptions(otMessage* aMessage, const char* aUriPath);
    otError MessageAppendUriQueryOption(otMessage* aMessage, const char* aUriQuery);
    otError MessageInitResponse(otMessage* aResponse, const otMessage* aRequest, otCoapType aType, otCoapCode aCode);
    otError MessageSetPayloadMarker(otMessage* aMessage);
    otError MessageSetToken(otMessage* aMessage, const uint8_t* aToken, uint8_t aTokenLength);
    otError OptionIteratorGetOptionUintValue(otCoapOptionIterator* aIterator, uint64_t* const aValue);
    otError OptionIteratorGetOptionValue(otCoapOptionIterator* aIterator, void* aValue);
    otError OptionIteratorInit(otCoapOptionIterator* aIterator, const otMessage* aMessage);
    otError SendRequestWithParameters(otMessage* aMessage, const otMessageInfo* aMessageInfo, otCoapResponseHandler aHandler, void* aContext, const otCoapTxParameters* aTxParameters);
    otError SendResponseWithParameters(otMessage* aMessage, const otMessageInfo* aMessageInfo, const otCoapTxParameters* aTxParameters);
    otError Start(uint16_t aPort);
    otError Stop();
    otMessage* NewMessage(const otMessageSettings* aSettings);
    static otError SendRequest(otMessage* aMessage, const otMessageInfo* aMessageInfo, otCoapResponseHandler aHandler, void* aContext);
    static otError SendResponse(otMessage* aMessage, const otMessageInfo* aMessageInfo);
    uint16_t BlockSizeFromExponent(otCoapBlockSize aSize);
    uint16_t MessageGetMessageId(const otMessage* aMessage);
    uint8_t MessageGetTokenLength(const otMessage* aMessage);
    void MessageGenerateToken(otMessage* aMessage, uint8_t aTokenLength);
    void MessageInit(otMessage* aMessage, otCoapType aType, otCoapCode aCode);
    void RemoveResource(otCoapResource* aResource);
    void SetDefaultHandler(otCoapRequestHandler aHandler, void* aContext);
  };

  class OpenThreadCoapSecureClass {
  friend class OpenThreadClass;
  public:
    bool IsConnected();
    bool IsConnectionActive();
    otError AddResource(otCoapResource* aResource);
    otError Connect(const otSockAddr* aSockAddr, otHandleCoapSecureClientConnect aHandler, void* aContext);
    otError GetPeerCertificateBase64(unsigned char* aPeerCert, size_t* aCertLength, size_t aCertBufferSize);
    otError SendRequest(otMessage* aMessage, otCoapResponseHandler aHandler, void* aContext);
    otError SendResponse(otMessage* aMessage, const otMessageInfo* aMessageInfo);
    otError Start(uint16_t aPort);
    void Disconnect();
    void RemoveResource(otCoapResource* aResource);
    void SetCaCertificateChain(const uint8_t* aX509CaCertificateChain, uint32_t aX509CaCertChainLength);
    void SetCertificate(const uint8_t* aX509Cert, uint32_t aX509Length, const uint8_t* aPrivateKey, uint32_t aPrivateKeyLength);
    void SetClientConnectedCallback(otHandleCoapSecureClientConnect aHandler, void* aContext);
    void SetDefaultHandler(otCoapRequestHandler aHandler, void* aContext);
    void SetPsk(const uint8_t* aPsk, uint16_t aPskLength, const uint8_t* aPskIdentity, uint16_t aPskIdLength);
    void SetSslAuthMode(bool aVerifyPeerCertificate);
    void Stop();
  };

  class OpenThreadCommissionerClass {
  friend class OpenThreadClass;
  public:
    const char* GetProvisioningUrl();
    otCommissionerState GetState();
    otError AddJoiner(const otExtAddress* aEui64, const char* aPskd, uint32_t aTimeout);
    otError AnnounceBegin(uint32_t aChannelMask, uint8_t aCount, uint16_t aPeriod, const otIp6Address* aAddress);
    otError EnergyScan(uint32_t aChannelMask, uint8_t aCount, uint16_t aPeriod, uint16_t aScanDuration, const otIp6Address* aAddress, otCommissionerEnergyReportCallback aCallback, void* aContext);
    otError GetNextJoinerInfo(uint16_t* aIterator, otJoinerInfo* aJoiner);
    otError PanIdQuery(uint16_t aPanId, uint32_t aChannelMask, const otIp6Address* aAddress, otCommissionerPanIdConflictCallback aCallback, void* aContext);
    otError RemoveJoiner(const otExtAddress* aEui64);
    otError SendMgmtGet(const uint8_t* aTlvs, uint8_t aLength);
    otError SendMgmtSet(const otCommissioningDataset* aDataset, const uint8_t* aTlvs, uint8_t aLength);
    otError SetProvisioningUrl(const char* aProvisioningUrl);
    otError Start(otCommissionerStateCallback aStateCallback, otCommissionerJoinerCallback aJoinerCallback, void* aCallbackContext);
    otError Stop();
    uint16_t GetSessionId();
  };

  class OpenThreadCryptoClass {
  friend class OpenThreadClass;
  public:
    otError EcdsaSign(uint8_t* aOutput, uint16_t* aOutputLength, const uint8_t* aInputHash, uint16_t aInputHashLength, const uint8_t* aPrivateKey, uint16_t aPrivateKeyLength);
    void AesCcm(const uint8_t* aKey, uint16_t aKeyLength, uint8_t aTagLength, const void* aNonce, uint8_t aNonceLength, const void* aHeader, uint32_t aHeaderLength, void* aPlainText, void* aCipherText, uint32_t aLength, bool aEncrypt, void* aTag);
    void HmacSha256(const uint8_t* aKey, uint16_t aKeyLength, const uint8_t* aBuf, uint16_t aBufLength, uint8_t* aHash);
  };

  class OpenThreadDatasetClass {
  friend class OpenThreadClass;
  public:
    bool IsCommissioned();
    otError GeneratePskc(const char* aPassPhrase, const otNetworkName* aNetworkName, const otExtendedPanId* aExtPanId, otPskc* aPskc);
    otError GetActive(otOperationalDataset* aDataset);
    otError GetPending(otOperationalDataset* aDataset);
    otError SendMgmtActiveGet(const otOperationalDatasetComponents* aDatasetComponents, const uint8_t* aTlvTypes, uint8_t aLength, const otIp6Address* aAddress);
    otError SendMgmtActiveSet(const otOperationalDataset* aDataset, const uint8_t* aTlvs, uint8_t aLength);
    otError SendMgmtPendingGet(const otOperationalDatasetComponents* aDatasetComponents, const uint8_t* aTlvTypes, uint8_t aLength, const otIp6Address* aAddress);
    otError SendMgmtPendingSet(const otOperationalDataset* aDataset, const uint8_t* aTlvs, uint8_t aLength);
    otError SetActive(const otOperationalDataset* aDataset);
    otError SetPending(const otOperationalDataset* aDataset);
    otError CreateNewNetwork(otOperationalDataset* aDataset);
    otError SetDelayTimerMinimal(uint32_t aDelayTimerMinimal);
    uint32_t GetDelayTimerMinimal();
  };

  class OpenThreadDiagClass {
  friend class OpenThreadClass;
  public:
    bool IsEnabled();
    otError ProcessCmd(uint8_t aArgsLength, char* aArgs[], char* aOutput, size_t aOutputMaxLen);
    void ProcessCmdLine(const char* aString, char* aOutput, size_t aOutputMaxLen);
  };

  class OpenThreadDnsClientClass {
  friend class OpenThreadClass;
  public:
    otError Query(const otDnsQuery* aQuery, otDnsResponseHandler aHandler, void* aContext);
  };

  class OpenThreadEntropyClass {
  friend class OpenThreadClass;
  public:
    mbedtls_entropy_context* MbedTlsContextGet(void);
  };

  class OpenThreadHeapClass {
  friend class OpenThreadClass;
  public:
    void Free(void* aPointer);
    void SetCAllocFree(otHeapCAllocFn aCAlloc, otHeapFreeFn aFree);
    void* CAlloc(size_t aCount, size_t aSize);
  };

  class OpenThreadIcmp6Class {
  friend class OpenThreadClass;
  public:
    otError RegisterHandler(otIcmp6Handler* aHandler);
    otError SendEchoRequest(otMessage* aMessage, const otMessageInfo* aMessageInfo, uint16_t aIdentifier);
    otIcmp6EchoMode GetEchoMode();
    void SetEchoMode(otIcmp6EchoMode aMode);
  };

  class OpenThreadInstanceClass {
  friend class OpenThreadClass;
  public:
    bool IsInitialized();
    otError ErasePersistentInfo();
    otInstance* Init(void* aInstanceBuffer, size_t* aInstanceBufferSize);
    otInstance* InitSingle(void);
    void FactoryReset();
    void Finalize();
    void Reset();
  };

  class OpenThreadIp6Class {
  friend class OpenThreadClass;
  public:
    bool IsAddressEqual(const otIp6Address* aFirst, const otIp6Address* aSecond);
    bool IsAddressUnspecified(const otIp6Address* aAddress);
    bool IsEnabled();
    bool IsMulticastPromiscuousEnabled();
    bool IsReceiveFilterEnabled();
    bool IsSlaacEnabled();
    const otNetifAddress* GetUnicastAddresses();
    const otNetifMulticastAddress* GetMulticastAddresses();
    const uint16_t* GetUnsecurePorts(uint8_t* aNumEntries);
    otError AddUnicastAddress(const otNetifAddress* aAddress);
    otError AddUnsecurePort(uint16_t aPort);
    otError AddressFromString(const char* aString, otIp6Address* aAddress);
    otError RemoveUnicastAddress(const otIp6Address* aAddress);
    otError RemoveUnsecurePort(uint16_t aPort);
    otError SelectSourceAddress(otMessageInfo* aMessageInfo);
    otError Send(otMessage* aMessage);
    otError SetEnabled(bool aEnabled);
    otError SubscribeMulticastAddress(const otIp6Address* aAddress);
    otError UnsubscribeMulticastAddress(const otIp6Address* aAddress);
    otMessage* NewMessage(const otMessageSettings* aSettings);
    otMessage* NewMessageFromBuffer(const uint8_t* aData, uint16_t aDataLength, const otMessageSettings* aSettings);
    uint8_t PrefixMatch(const otIp6Address* aFirst, const otIp6Address* aSecond);
    void RemoveAllUnsecurePorts();
    void SetAddressCallback(otIp6AddressCallback aCallback, void* aCallbackContext);
    void SetMulticastPromiscuousEnabled(bool aEnabled);
    void SetReceiveCallback(otIp6ReceiveCallback aCallback, void* aCallbackContext);
    void SetReceiveFilterEnabled(bool aEnabled);
    void SetSlaacEnabled(bool aEnabled);
    void SetSlaacPrefixFilter(otIp6SlaacPrefixFilter aFilter);
  };

  class OpenThreadJamDetectionClass {
  friend class OpenThreadClass;
  public:
    bool GetState();
    bool IsEnabled();
    int8_t GetRssiThreshold();
    otError SetBusyPeriod(uint8_t aBusyPeriod);
    otError SetRssiThreshold(int8_t aRssiThreshold);
    otError SetWindow(uint8_t aWindow);
    otError Start(otJamDetectionCallback aCallback, void* aContext);
    otError Stop();
    uint64_t GetHistoryBitmap();
    uint8_t GetBusyPeriod();
    uint8_t GetWindow();
  };

  class OpenThreadJoinerClass {
  friend class OpenThreadClass;
  public:
    otError Start(const char* aPskd, const char* aProvisioningUrl, const char* aVendorName, const char* aVendorModel, const char* aVendorSwVersion, const char* aVendorData, otJoinerCallback aCallback, void* aContext);
    otJoinerState GetState();
    void GetId(otExtAddress* aJoinerId);
    void Stop();
  };

  class OpenThreadLinkClass {
  friend class OpenThreadClass;
  public:
    bool IsActiveScanInProgress();
    bool IsEnabled();
    bool IsEnergyScanInProgress();
    bool IsInTransmitState();
    bool IsPromiscuous();
    const otExtAddress* GetExtendedAddress();
    const otMacCounters* GetCounters();
    const uint32_t* GetTxDirectRetrySuccessHistogram(uint8_t* aNumberOfEntries);
    const uint32_t* GetTxIndirectRetrySuccessHistogram(uint8_t* aNumberOfEntries);
    int8_t ConvertLinkQualityToRss(uint8_t aLinkQuality);
    otError ActiveScan(uint32_t aScanChannels, uint16_t aScanDuration, otHandleActiveScanResult aCallback, void* aCallbackContext);
    otError EnergyScan(uint32_t aScanChannels, uint16_t aScanDuration, otHandleEnergyScanResult aCallback, void* aCallbackContext);
    otError FilterAddAddress(const otExtAddress* aExtAddress);
    otError FilterAddRssIn(const otExtAddress* aExtAddress, int8_t aRss);
    otError FilterGetNextAddress(otMacFilterIterator* aIterator, otMacFilterEntry* aEntry);
    otError FilterGetNextRssIn(otMacFilterIterator* aIterator, otMacFilterEntry* aEntry);
    otError FilterRemoveAddress(const otExtAddress* aExtAddress);
    otError FilterRemoveRssIn(const otExtAddress* aExtAddress);
    otError FilterSetAddressMode(otMacFilterAddressMode aMode);
    otError OutOfBandTransmitRequest(otRadioFrame* aOobFrame);
    otError SendDataRequest();
    otError SetChannel(uint8_t aChannel);
    otError SetEnabled(bool aEnable);
    otError SetExtendedAddress(const otExtAddress* aExtAddress);
    otError SetPanId(otPanId aPanId);
    otError SetPollPeriod(uint32_t aPollPeriod);
    otError SetPromiscuous(bool aPromiscuous);
    otError SetSupportedChannelMask(uint32_t aChannelMask);
    otMacFilterAddressMode FilterGetAddressMode();
    otPanId GetPanId();
    otShortAddress GetShortAddress();
    uint16_t GetCcaFailureRate();
    uint32_t GetPollPeriod();
    uint32_t GetSupportedChannelMask();
    uint8_t ConvertRssToLinkQuality(int8_t aRss);
    uint8_t GetChannel();
    uint8_t GetMaxFrameRetriesDirect();
    uint8_t GetMaxFrameRetriesIndirect();
    void FilterClearAddresses();
    void FilterClearRssIn();
    void GetFactoryAssignedIeeeEui64(otExtAddress* aEui64);
    void ResetCounters();
    void ResetTxRetrySuccessHistogram();
    void SetMaxFrameRetriesDirect(uint8_t aMaxFrameRetriesDirect);
    void SetMaxFrameRetriesIndirect(uint8_t aMaxFrameRetriesIndirect);
    void SetPcapCallback(otLinkPcapCallback aPcapCallback, void* aCallbackContext);
    bool RawGetPromiscuous();
    bool RawIsEnabled();
    int8_t RawGetRssi();
    otError RawEnergyScan(uint8_t aScanChannel, uint16_t aScanDuration, otLinkRawEnergyScanDone aCallback);
    otError RawReceive(otLinkRawReceiveDone aCallback);
    otError RawSetEnable(bool aEnabled);
    otError RawSetPromiscuous(bool aEnable);
    otError RawSetShortAddress(uint16_t aShortAddress);
    otError RawSleep();
    otError RawSrcMatchAddExtEntry(const otExtAddress* aExtAddress);
    otError RawSrcMatchAddShortEntry(uint16_t aShortAddress);
    otError RawSrcMatchClearExtEntries();
    otError RawSrcMatchClearExtEntry(const otExtAddress* aExtAddress);
    otError RawSrcMatchClearShortEntries();
    otError RawSrcMatchClearShortEntry(uint16_t aShortAddress);
    otError RawSrcMatchEnable(bool aEnable);
    otError RawTransmit(otLinkRawTransmitDone aCallback);
    otRadioCaps RawGetCaps();
    otRadioFrame* RawGetTransmitBuffer();
  };

  class OpenThreadLoggingClass {
  friend class OpenThreadClass;
  public:
    otLogLevel GetLevel(void);
    void SetLevel(otLogLevel aLogLevel);
  };

  class OpenThreadMessageClass {
  friend class OpenThreadClass;
  public:
    bool IsLinkSecurityEnabled(const otMessage* aMessage);
    int Write(otMessage* aMessage, uint16_t aOffset, const void* aBuf, uint16_t aLength);
    int8_t GetRss(const otMessage* aMessage);
    otError Append(otMessage* aMessage, const void* aBuf, uint16_t aLength);
    otError QueueDequeue(otMessageQueue* aQueue, otMessage* aMessage);
    otError QueueEnqueue(otMessageQueue* aQueue, otMessage* aMessage);
    otError QueueEnqueueAtHead(otMessageQueue* aQueue, otMessage* aMessage);
    otError SetLength(otMessage* aMessage, uint16_t aLength);
    otError SetOffset(otMessage* aMessage, uint16_t aOffset);
    otMessage* QueueGetHead(otMessageQueue* aQueue);
    otMessage* QueueGetNext(otMessageQueue* aQueue, const otMessage* aMessage);
    uint16_t GetLength(const otMessage* aMessage);
    uint16_t GetOffset(const otMessage* aMessage);
    uint16_t Read(const otMessage* aMessage, uint16_t aOffset, void* aBuf, uint16_t aLength);
    void Free(otMessage* aMessage);
    void GetBufferInfo(otBufferInfo* aBufferInfo);
    void QueueInit(otMessageQueue* aQueue);
    void SetDirectTransmission(otMessage* aMessage, bool aEnabled);
  };

  class OpenThreadNcpClass {
  friend class OpenThreadClass;
  public:
    otError StreamWrite(int aStreamId, const uint8_t* aDataPtr, int aDataLen);
    void HandleDidReceiveNewLegacyUlaPrefix(const uint8_t* aUlaPrefix);
    void HandleLegacyNodeDidJoin(const otExtAddress* aExtAddr);
    void Init();
    void PlatLogv(otLogLevel aLogLevel, otLogRegion aLogRegion, const char* aFormat, va_list aArgs);
    void RegisterLegacyHandlers(const otNcpLegacyHandlers* aHandlers);
    void RegisterPeekPokeDelagates(otNcpDelegateAllowPeekPoke aAllowPeekDelegate, otNcpDelegateAllowPeekPoke aAllowPokeDelegate);
  };

  class OpenThreadNetDataClass {
  friend class OpenThreadClass;
  public:
    otError Get(bool aStable, uint8_t* aData, uint8_t* aDataLength);
    otError GetNextOnMeshPrefix(otNetworkDataIterator* aIterator, otBorderRouterConfig* aConfig);
    otError GetNextRoute(otNetworkDataIterator* aIterator, otExternalRouteConfig* aConfig);
    otError GetNextService(otNetworkDataIterator* aIterator, otServiceConfig* aConfig);
    uint8_t GetStableVersion();
    uint8_t GetVersion();
  };

  class OpenThreadNetworkTimeClass {
  friend class OpenThreadClass;
  public:
    otError SetSyncPeriod(uint16_t aTimeSyncPeriod);
    otError SetXtalThreshold(uint16_t aXTALThreshold);
    otNetworkTimeStatus Get(uint64_t* aNetworkTime);
    uint16_t GetSyncPeriod();
    uint16_t GetXtalThreshold();
    void SyncSetCallback(otNetworkTimeSyncCallbackFn aCallbackFn, void* aCallbackContext);
  };

  class OpenThreadPlatClass {
  friend class OpenThreadClass;
  public:
    bool DiagModeGet(void);
    otError DiagProcess(uint8_t aArgsLength, char* aArgs[], char* aOutput, size_t aOutputMaxLen);
    void DiagAlarmCallback();
    void DiagChannelSet(uint8_t aChannel);
    void DiagModeSet(bool aMode);
    void DiagRadioReceived(otRadioFrame* aFrame, otError aError);
    void DiagTxPowerSet(int8_t aTxPower);
    otError EntropyGet(uint8_t* aOutput, uint16_t aOutputLength);
    void Log(otLogLevel aLogLevel, otLogRegion aLogRegion, const char* aFormat,...);
    otError UdpBind(otUdpSocket* aUdpSocket);
    otError UdpClose(otUdpSocket* aUdpSocket);
    otError UdpConnect(otUdpSocket* aUdpSocket);
    otError UdpSend(otUdpSocket* aUdpSocket, otMessage* aMessage, const otMessageInfo* aMessageInfo);
    otError UdpSocket(otUdpSocket* aUdpSocket);
  };

  class OpenThreadRandomCryptoClass {
  friend class OpenThreadClass;
  public:
    mbedtls_ctr_drbg_context* MbedTlsContextGet(void);
    otError FillBuffer(uint8_t* aBuffer, uint16_t aSize);
  };

  class OpenThreadRandomNonCryptoClass {
  friend class OpenThreadClass;
  public:
    uint16_t GetUint16(void);
    uint16_t GetUint16InRange(uint16_t aMin, uint16_t aMax);
    uint32_t AddJitter(uint32_t aValue, uint16_t aJitter);
    uint32_t GetUint32(void);
    uint32_t GetUint32InRange(uint32_t aMin, uint32_t aMax);
    uint8_t GetUint8(void);
    uint8_t GetUint8InRange(uint8_t aMin, uint8_t aMax);
    void FillBuffer(uint8_t* aBuffer, uint16_t aSize);
  };

  class OpenThreadServerClass {
  friend class OpenThreadClass;
  public:
    otError AddService(const otServiceConfig* aConfig);
    otError GetNetDataLocal(bool aStable, uint8_t* aData, uint8_t* aDataLength);
    otError GetNextService(otNetworkDataIterator* aIterator, otServiceConfig* aConfig);
    otError Register();
    otError RemoveService(uint32_t aEnterpriseNumber, const uint8_t* aServiceData, uint8_t aServiceDataLength);
  };

  class OpenThreadSntpClientClass {
  friend class OpenThreadClass;
  public:
    otError Query(const otSntpQuery* aQuery, otSntpResponseHandler aHandler, void* aContext);
    void SetUnixEra(uint32_t aUnixEra);
  };

  class OpenThreadTaskletsClass {
  friend class OpenThreadClass;
  public:
    bool ArePending();
    void Process();
    void SignalPending();
  };

  class OpenThreadThreadClass {
  friend class OpenThreadClass;
  public:
    const char* ErrorToString(otError aError);
    otError GetNextDiagnosticTlv(const otMessage* aMessage, otNetworkDiagIterator* aIterator, otNetworkDiagTlv* aNetworkDiagTlv);
    otError SendDiagnosticGet(const otIp6Address* aDestination, const uint8_t aTlvTypes[], uint8_t aCount);
    otError SendDiagnosticReset(const otIp6Address* aDestination, const uint8_t aTlvTypes[], uint8_t aCount);
    void SetReceiveDiagnosticGetCallback(otReceiveDiagnosticGetCallback aCallback, void* aCallbackContext);
    bool IsDiscoverInProgress();
    bool IsSingleton();
    const char* GetNetworkName();
    const otExtendedPanId* GetExtendedPanId();
    const otIp6Address* GetLinkLocalIp6Address();
    const otIp6Address* GetMeshLocalEid();
    const otIp6Address* GetRloc();
    const otIpCounters* GetIp6Counters();
    const otMasterKey* GetMasterKey();
    const otMeshLocalPrefix* GetMeshLocalPrefix();
    const otMleCounters* GetMleCounters();
    otDeviceRole GetDeviceRole();
    otError BecomeChild();
    otError BecomeDetached();
    otError Discover(uint32_t aScanChannels, uint16_t aPanId, bool aJoiner, bool aEnableEui64Filtering, otHandleActiveScanResult aCallback, void* aCallbackContext);
    otError GetLeaderData(otLeaderData* aLeaderData);
    otError GetLeaderRloc(otIp6Address* aLeaderRloc);
    otError GetNextNeighborInfo(otNeighborInfoIterator* aIterator, otNeighborInfo* aInfo);
    otError GetParentAverageRssi(int8_t* aParentRssi);
    otError GetParentInfo(otRouterInfo* aParentInfo);
    otError GetParentLastRssi(int8_t* aLastRssi);
    otError SetEnabled(bool aEnabled);
    otError SetExtendedPanId(const otExtendedPanId* aExtendedPanId);
    otError SetLinkMode(otLinkModeConfig aConfig);
    otError SetMasterKey(const otMasterKey* aKey);
    otError SetMeshLocalPrefix(const otMeshLocalPrefix* aMeshLocalPrefix);
    otError SetNetworkName(const char* aNetworkName);
    otLinkModeConfig GetLinkMode();
    uint16_t GetRloc16();
    uint16_t GetVersion();
    uint32_t GetChildTimeout();
    uint32_t GetKeySequenceCounter();
    uint32_t GetKeySwitchGuardTime();
    uint32_t GetPartitionId();
    uint8_t GetLeaderRouterId();
    uint8_t GetLeaderWeight();
    void RegisterParentResponseCallback(otThreadParentResponseCallback aCallback, void* aContext);
    void ResetIp6Counters();
    void ResetMleCounters();
    void SetChildTimeout(uint32_t aTimeout);
    void SetKeySequenceCounter(uint32_t aKeySequenceCounter);
    void SetKeySwitchGuardTime(uint32_t aKeySwitchGuardTime);
    bool IsRouterEligible();
    const otPskc* GetPskc();
    int8_t GetParentPriority();
    otError BecomeLeader();
    otError BecomeRouter();
    otError GetChildInfoById(uint16_t aChildId, otChildInfo* aChildInfo);
    otError GetChildInfoByIndex(uint16_t aChildIndex, otChildInfo* aChildInfo);
    otError GetChildNextIp6Address(uint16_t aChildIndex, otChildIp6AddressIterator* aIterator, otIp6Address* aAddress);
    otError GetNextCacheEntry(otCacheEntryInfo* aEntryInfo, otCacheEntryIterator* aIterator);
    otError GetRouterInfo(uint16_t aRouterId, otRouterInfo* aRouterInfo);
    otError ReleaseRouterId(uint8_t aRouterId);
    otError SetJoinerUdpPort(uint16_t aJoinerUdpPort);
    otError SetMaxAllowedChildren(uint16_t aMaxChildren);
    otError SetMaxChildIpAddresses(uint8_t aMaxIpAddresses);
    otError SetParentPriority(int8_t aParentPriority);
    otError SetPreferredRouterId(uint8_t aRouterId);
    otError SetPskc(const otPskc* aPskc);
    otError SetRouterEligible(bool aEligible);
    uint16_t GetJoinerUdpPort();
    uint16_t GetMaxAllowedChildren();
    uint32_t GetContextIdReuseDelay();
    uint32_t GetLocalLeaderPartitionId();
    uint8_t GetLocalLeaderWeight();
    uint8_t GetMaxChildIpAddresses();
    uint8_t GetMaxRouterId();
    uint8_t GetNetworkIdTimeout();
    uint8_t GetRouterDowngradeThreshold();
    uint8_t GetRouterIdSequence();
    uint8_t GetRouterSelectionJitter();
    uint8_t GetRouterUpgradeThreshold();
    void RegisterNeighborTableCallback(otNeighborTableCallback aCallback);
    void SetContextIdReuseDelay(uint32_t aDelay);
    void SetLocalLeaderPartitionId(uint32_t aPartitionId);
    void SetLocalLeaderWeight(uint8_t aWeight);
    void SetNetworkIdTimeout(uint8_t aTimeout);
    void SetRouterDowngradeThreshold(uint8_t aThreshold);
    void SetRouterSelectionJitter(uint8_t aRouterJitter);
    void SetRouterUpgradeThreshold(uint8_t aThreshold);
    void SetSteeringData(const otExtAddress* aExtAddress);
  };

  class OpenThreadUdpClass {
  friend class OpenThreadClass;
  public:
    otError AddReceiver(otUdpReceiver* aUdpReceiver);
    otError Bind(otUdpSocket* aSocket, otSockAddr* aSockName);
    otError Close(otUdpSocket* aSocket);
    otError Connect(otUdpSocket* aSocket, otSockAddr* aSockName);
    otError Open(otUdpSocket* aSocket, otUdpReceive aCallback, void* aContext);
    otError RemoveReceiver(otUdpReceiver* aUdpReceiver);
    otError Send(otUdpSocket* aSocket, otMessage* aMessage, const otMessageInfo* aMessageInfo);
    otError SendDatagram(otMessage* aMessage, otMessageInfo* aMessageInfo);
    otMessage* NewMessage(const otMessageSettings* aSettings);
    otUdpSocket* GetSockets();
    void ForwardReceive(otMessage* aMessage, uint16_t aPeerPort, const otIp6Address* aPeerAddr, uint16_t aSockPort);
    void ForwardSetForwarder(otUdpForwarder aForwarder, void* aContext);
  };

