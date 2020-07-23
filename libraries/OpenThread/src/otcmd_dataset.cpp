
#include "OpenThread.h"

#include <Arduino.h>

#include <openthread/config.h>
#include <openthread/commissioner.h>
#include <openthread/icmp6.h>
#include <openthread/joiner.h>
#include <openthread/link.h>
#if OPENTHREAD_CONFIG_ENABLE_TIME_SYNC
#include <openthread/network_time.h>

#include <openthread/dns.h>

#if OPENTHREAD_FTD
#include <openthread/dataset_ftd.h>
#include <openthread/thread_ftd.h>
#endif

#if OPENTHREAD_CONFIG_BORDER_ROUTER_ENABLE
#include <openthread/border_router.h>
#endif
#if OPENTHREAD_CONFIG_SERVICE_ENABLE
#include <openthread/server.h>
#endif
#endif

#include <openthread/heap.h>

extern "C" {
#include <openthread/openthread-freertos.h>
}

otError OTDataset::init_active() {
  return otDatasetGetActive(otrGetInstance(), &mDataset);
}

otError OTDataset::init_pending() {
  return otDatasetGetPending(otrGetInstance(), &mDataset);
}

otError OTDataset::init_new() {
  return otDatasetCreateNewNetwork(otrGetInstance(), &mDataset);
}

otError OTDataset::commit_active() {
  return otDatasetSetActive(otrGetInstance(), &mDataset);
}
otError OTDataset::commit_pending() {
  return otDatasetSetPending(otrGetInstance(), &mDataset);
}

void OTDataset::clear() {
  memset(&mDataset, 0, sizeof(mDataset));
}

void OTDataset::delay(uint32_t delay) {
  mDataset.mDelay = delay;
  mDataset.mComponents.mIsDelayPresent = true;
}

void OTDataset::extpanid(const otExtendedPanId* panid)
{
  memcpy(&mDataset.mExtendedPanId, panid, sizeof(otExtendedPanId));
  mDataset.mComponents.mIsExtendedPanIdPresent = true;
}

void OTDataset::masterkey(const otMasterKey* masterkey)
{
  memcpy(&mDataset.mMasterKey, masterkey, sizeof(otMasterKey));
  mDataset.mComponents.mIsMasterKeyPresent = true;
}

void OTDataset::meshlocalprefix(const otIp6Prefix* prefix)
{
  memcpy(&mDataset.mMeshLocalPrefix, prefix, sizeof(otIp6Prefix));
  mDataset.mComponents.mIsMeshLocalPrefixPresent = true;
}

void OTDataset::networkname(const char* netname)
{
  memcpy(&mDataset.mNetworkName, netname, sizeof(otNetworkName));
  mDataset.mComponents.mIsNetworkNamePresent = true;
}

void OTDataset::panid(otPanId panid)
{
  mDataset.mPanId = panid;
  mDataset.mComponents.mIsPanIdPresent = true;
}

void OTDataset::activetimestamp(uint64_t timestamp)
{
  mDataset.mActiveTimestamp = timestamp;
  mDataset.mComponents.mIsActiveTimestampPresent = true;
}
void OTDataset::pendingtimestamp(uint64_t timestamp)
{
  mDataset.mPendingTimestamp = timestamp;
  mDataset.mComponents.mIsPendingTimestampPresent = true;
}
void OTDataset::channel(uint16_t channel)
{
  mDataset.mChannel = channel;
  mDataset.mComponents.mIsChannelPresent = true;
}
void OTDataset::channelmask(uint32_t channelmask)
{
  mDataset.mChannelMask = channelmask;
  mDataset.mComponents.mIsChannelMaskPresent = true;
}

void OTDataset::pskc(const otPskc* pskc_)
{
  memcpy(&mDataset.mNetworkName, pskc_, sizeof(otPskc));
  mDataset.mComponents.mIsPskcPresent = true;
}

void OTDataset::securitypolicy(uint16_t rotationtime, uint32_t flags)
{
  mDataset.mSecurityPolicy.mRotationTime = rotationtime;
  mDataset.mSecurityPolicy.mFlags = flags;
  mDataset.mComponents.mIsSecurityPolicyPresent = true;
}

otError OTDataset::pskc_passphrase(const char* passphrase)
{
  otError error;
  otPskc pskc_;
  error = otDatasetGeneratePskc(passphrase,
            (mDataset.mComponents.mIsNetworkNamePresent
              ? &mDataset.mNetworkName
              : reinterpret_cast<const otNetworkName*>(otThreadGetNetworkName(otrGetInstance()))),
            (mDataset.mComponents.mIsExtendedPanIdPresent
	      ? &mDataset.mExtendedPanId
	      : otThreadGetExtendedPanId(otrGetInstance())),
            &pskc_);

  if(error) return error;

  pskc(&pskc_);
  return OT_ERROR_NONE;
}

