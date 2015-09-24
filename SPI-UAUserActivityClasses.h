//
//  SPI-UAUserActivitClasses.h
//  RemindersImport
//
//  Created by Daniel Jalkut on 9/23/15.
//  Copyright © 2015 Bitsplitting. All rights reserved.
//

// WARNING this header file describes the interfaces of private Apple classes.
// It should not be relied upon or shipped with production code.

@class UAUserActivityManager;

@interface UAUserActivity : NSObject
{
    UAUserActivityManager *_manager;
    NSMutableDictionary *_userInfo;
    NSMutableDictionary *_frameworkPayload;
    NSString *_title;
    NSURL *_webpageURL;
    id _delegate;
    id _advertiser;
    id _resumerAdvertiser;
    double _lastSaveTime;
    BOOL _saveScheduled;
    BOOL _createsNewUUIDIfSaved;
    NSError *_decodeUserInfoError;
    BOOL _needsSave;
    BOOL _dirty;
    BOOL _sendToServerPending;
    BOOL _activityHasBeenSentToServer;
    BOOL _supportsContinuationStreams;
    BOOL _forceImmediateSendToServer;
    BOOL _encodedContainsUnsynchronizedCloudDocument;
    BOOL _encodedFileProviderURL;
    long long _inWillSaveCallback;
    double _encodedContainsUnsynchronizedCloudDocumentBackoffInterval;
    id _contentAttributeSet;
    NSMutableSet *_keywords;
    NSDate *_expirationDate;
    NSString *_contentUserAction;
    NSMutableSet *_requiredUserInfoKeys;
    NSString *_teamIdentifier;
    BOOL _eligibleForHandoff;
    BOOL _eligibleForSearch;
    BOOL _eligibleForReminders;
    BOOL _eligibleForPublicIndexing;
    BOOL _invalidated;
    BOOL _canCreateStreams;
    NSData *_cachedEncodedUserInfo;
    NSString *_typeIdentifier;
    NSString *_dynamicIdentifier;
    NSUUID *_uniqueIdentifier;
    unsigned long long _suggestedActionType;
    NSDictionary *_options;
    NSData *_streamsData;
}

//+ (void)removeDynamicUserActivity:(id)arg1 matching:(id)arg2;
//+ (void)addDynamicUserActivity:(id)arg1 matching:(id)arg2;
//+ (void)initialize;
//+ (id)fetchUserActivityWithUUID:(id)arg1 intervalToWaitForDocumentSynchronizationToComplete:(double)arg2 completionHandler:(CDUnknownBlockType)arg3;
//+ (void)fetchUserActivityWithUUID:(id)arg1 completionHandler:(CDUnknownBlockType)arg2;
//+ (id)userActivityFromUUID:(id)arg1 withError:(id *)arg2;
//+ (id)userActivityFromUUID:(id)arg1 timeout:(double)arg2 withError:(id *)arg3;
//+ (id)userActivity;
//+ (BOOL)userActivityContinuationSupported;
//+ (BOOL)checkWebpageURL:(id)arg1 actionType:(unsigned long long)arg2 throwIfFailed:(BOOL)arg3;
//+ (id)allowedWebpageURLSchemes;
//+ (void)unregisterForSuggestedActionNudgeOfType:(id)arg1;
//+ (id)registerForSuggestedActionNudgeOfType:(unsigned long long)arg1 withOptions:(id)arg2 block:(CDUnknownBlockType)arg3;
//+ (BOOL)currentUserActivityUUIDWithOptions:(id)arg1 completionHandler:(CDUnknownBlockType)arg2;
//+ (id)currentUserActivityUUID;
//+ (BOOL)supportsUserActivityAppLinks;
//+ (id)_decodeFromString:(id)arg1;
//+ (id)_decodeFromScanner:(id)arg1;
//+ (id)_encodeKeyAndValueIntoString:(id)arg1 value:(id)arg2;
//+ (id)_encodeToString:(id)arg1;
//@property BOOL canCreateStreams; // @synthesize canCreateStreams=_canCreateStreams;
//@property(copy) NSData *streamsData; // @synthesize streamsData=_streamsData;
//@property(copy) NSDictionary *options; // @synthesize options=_options;
//@property(readonly) unsigned long long suggestedActionType; // @synthesize suggestedActionType=_suggestedActionType;
//@property(copy) NSUUID *uniqueIdentifier; // @synthesize uniqueIdentifier=_uniqueIdentifier;
//@property(copy) NSString *dynamicIdentifier; // @synthesize dynamicIdentifier=_dynamicIdentifier;
@property(copy) NSString *typeIdentifier; // @synthesize typeIdentifier=_typeIdentifier;
//@property(readonly, getter=isInvalidated) BOOL invalidated; // @synthesize invalidated=_invalidated;
//@property(retain) NSData *cachedEncodedUserInfo; // @synthesize cachedEncodedUserInfo=_cachedEncodedUserInfo;
//@property(readonly) BOOL activityHasBeenSentToServer; // @synthesize activityHasBeenSentToServer=_activityHasBeenSentToServer;
//@property BOOL encodedFileProviderURL; // @synthesize encodedFileProviderURL=_encodedFileProviderURL;
//@property double encodedContainsUnsynchronizedCloudDocumentBackoffInterval; // @synthesize encodedContainsUnsynchronizedCloudDocumentBackoffInterval=_encodedContainsUnsynchronizedCloudDocumentBackoffInterval;
//@property BOOL encodedContainsUnsynchronizedCloudDocument; // @synthesize encodedContainsUnsynchronizedCloudDocument=_encodedContainsUnsynchronizedCloudDocument;
//@property(retain) NSError *decodeUserInfoError; // @synthesize decodeUserInfoError=_decodeUserInfoError;
//@property BOOL createsNewUUIDIfSaved; // @synthesize createsNewUUIDIfSaved=_createsNewUUIDIfSaved;
//@property BOOL forceImmediateSendToServer; // @synthesize forceImmediateSendToServer=_forceImmediateSendToServer;
//@property BOOL sendToServerPending; // @synthesize sendToServerPending=_sendToServerPending;
//@property(copy) NSString *teamIdentifier; // @synthesize teamIdentifier=_teamIdentifier;
//@property(readonly, copy) NSString *debugDescription;
//@property(readonly, copy) NSString *description;
//@property(readonly) unsigned long long hash;
//- (BOOL)isEqual:(id)arg1;
//- (id)determineMatchingApplicationBundleIdentfierWithOptions:(id)arg1;
//- (void)pinUserActivityWithCompletionHandler:(CDUnknownBlockType)arg1;
//- (void)prepareUserActivityForLaunchingWithOptions:(id)arg1 completionHandler:(CDUnknownBlockType)arg2;
//@property(readonly) UAUserActivityManager *manager; // @dynamic manager;
//- (id)decodeUserInfo:(id)arg1;
//- (id)encodeUserInfo:(id)arg1;
//- (id)encodeUserInfo:(id)arg1 error:(id *)arg2;
//- (id)unarchiver:(id)arg1 didDecodeObject:(id)arg2;
//- (id)archiver:(id)arg1 willEncodeObject:(id)arg2;
//- (id)unarchiveURL:(id)arg1 error:(id *)arg2;
//- (id)archiveURL:(id)arg1 error:(id *)arg2;
//- (void)invalidate;
//- (void)resignCurrent;
//- (void)_resignCurrent;
//- (void)becomeCurrent;
//- (void)getContinuationStreamsWithCompletionHandler:(CDUnknownBlockType)arg1;
//@property id <UAUserActivityDelegate> delegate; // @dynamic delegate;
//@property BOOL supportsContinuationStreams; // @dynamic supportsContinuationStreams;
//- (void)indexActivity:(double)arg1 forceIndexing:(BOOL)arg2;
//- (id)teamID;
//@property BOOL needsSave; // @dynamic needsSave;
//@property BOOL dirty; // @dynamic dirty;
//- (void)addUserInfoEntriesFromDictionary:(id)arg1;
//@property(copy) NSURL *webpageURL; // @dynamic webpageURL;
@property(copy) NSDictionary *userInfo; // @dynamic userInfo;
@property(copy) NSString *title; // @dynamic title;
//- (void)dealloc;
//- (id)copyWithNewUUID;
//- (id)initDynamicActivityWithTypeIdentifier:(id)arg1 dynamicIdentifier:(id)arg2 suggestedActionType:(unsigned long long)arg3 options:(id)arg4;
//- (id)initWithTypeIdentifier:(id)arg1 dynamicIdentifier:(id)arg2 options:(id)arg3;
//- (id)initWithTypeIdentifier:(id)arg1 suggestedActionType:(unsigned long long)arg2 options:(id)arg3;
//- (id)initWithTypeIdentifier:(id)arg1 options:(id)arg2;
//- (id)initWithTypeIdentifier:(id)arg1;
//- (id)init;
//- (void)removeContentAttribute:(id)arg1;
//- (void)addContentAttribute:(id)arg1 forKey:(id)arg2;
//- (void)setContentAttributes:(id)arg1;
//- (id)contentAttributes;
//- (void)setContentType:(id)arg1;
//- (id)contentType;
//@property(copy) NSString *subtitle; // @dynamic subtitle;
//- (void)advertiser:(id)arg1 didReceiveInputStream:(id)arg2 outputStream:(id)arg3;
//- (long long)priority;
//- (void)sendUserActivityInfoToLSUserActivityd:(BOOL)arg1 onAsyncQueue:(BOOL)arg2;
//- (id)callWillSaveDelegateIfDirtyAndPackageUpData:(BOOL)arg1 clearDirty:(BOOL)arg2;
//- (id)userActivityInfoForSelf;
//- (void)scheduleSendUserActivityInfoToLSUserActivityd;
//- (void)didReceiveInputStream:(id)arg1 outputStream:(id)arg2;
//- (void)didSynchronizeUserActivity;
//- (void)willSynchronizeUserActivityWithHandler:(CDUnknownBlockType)arg1;
//- (void)tellDaemonAboutNewLSUserActivity;
- (id)initWithManager:(id)arg1 userActivityInfo:(id)arg2;
//@property(getter=isEligibleForPublicIndexing) BOOL eligibleForPublicIndexing; // @dynamic eligibleForPublicIndexing;
//@property(getter=isEligibleForReminders) BOOL eligibleForReminders; // @dynamic eligibleForReminders;
//@property(getter=isEligibleForSearch) BOOL eligibleForSearch; // @dynamic eligibleForSearch;
//@property(getter=isEligibleForHandoff) BOOL eligibleForHandoff; // @dynamic eligibleForHandoff;
//@property(retain) NSUserActivity *parentUserActivity; // @dynamic parentUserActivity;
//- (void)addKeywordsFromArray:(id)arg1;
//@property(copy) NSSet *requiredUserInfoKeys; // @dynamic requiredUserInfoKeys;
//@property(copy) NSSet *keywords; // @dynamic keywords;
//@property(copy) NSDate *expirationDate; // @dynamic expirationDate;
//@property(copy) NSString *contentIdentifier; // @dynamic contentIdentifier;
//@property(copy) NSString *contentUserAction; // @dynamic contentUserAction;
//@property(copy) CSSearchableItemAttributeSet *contentAttributeSet; // @dynamic contentAttributeSet;
//- (BOOL)createUserActivityDataWithSaving:(BOOL)arg1 options:(id)arg2 completionHandler:(CDUnknownBlockType)arg3;
//- (BOOL)_encodeIntoUserActivityDataWithSave:(BOOL)arg1 completionHandler:(CDUnknownBlockType)arg2;
//- (BOOL)createUserActivityStringsWithSaving:(BOOL)arg1 options:(id)arg2 completionHandler:(CDUnknownBlockType)arg3;
//- (BOOL)_encodeIntoUserActivityStringWithSave:(BOOL)arg1 completionHandler:(CDUnknownBlockType)arg2;
//- (id)initWithUserActivityData:(id)arg1 options:(id)arg2;
//- (id)initWithUserActivityStrings:(id)arg1 optionalString:(id)arg2 tertiaryData:(id)arg3 options:(id)arg4;
//
//// Remaining properties
//@property(readonly) Class superclass;
//
@end

@interface UAUserActivityInfo : NSObject <NSCopying, NSSecureCoding>
{
    BOOL _eligibleForHandoff;
    BOOL _eligibleForSearch;
    BOOL _eligibleForPublicIndex;
    NSUUID *_uuid;
    unsigned long long _type;
    NSDictionary *_options;
    unsigned long long _changeCount;
    NSDate *_activityDate;
    NSString *_title;
    NSString *_typeIdentifier;
    NSString *_dynamicIdentifier;
    NSString *_teamIdentifier;
    NSURL *_webpageURL;
    NSData *_streamsData;
    NSData *_encodedUserInfo;
    NSError *_encodedUserInfoError;
    NSSet *_requiredUserInfoKeys;
    NSDictionary *_encodingOptions;
    NSData *_contentAttributeSetData;
    NSString *_contentUserAction;
    NSSet *_keywords;
    NSDate *_expirationDate;
    NSError *_error;
}

//+ (BOOL)supportsSecureCoding;
//@property(copy) NSError *error; // @synthesize error=_error;
//@property(copy) NSDate *expirationDate; // @synthesize expirationDate=_expirationDate;
//@property(copy) NSSet *keywords; // @synthesize keywords=_keywords;
//@property(copy) NSString *contentUserAction; // @synthesize contentUserAction=_contentUserAction;
//@property(copy) NSData *contentAttributeSetData; // @synthesize contentAttributeSetData=_contentAttributeSetData;
//@property(copy) NSDictionary *encodingOptions; // @synthesize encodingOptions=_encodingOptions;
//@property BOOL eligibleForPublicIndex; // @synthesize eligibleForPublicIndex=_eligibleForPublicIndex;
//@property BOOL eligibleForSearch; // @synthesize eligibleForSearch=_eligibleForSearch;
//@property BOOL eligibleForHandoff; // @synthesize eligibleForHandoff=_eligibleForHandoff;
//@property(copy) NSSet *requiredUserInfoKeys; // @synthesize requiredUserInfoKeys=_requiredUserInfoKeys;
//@property(copy) NSError *encodedUserInfoError; // @synthesize encodedUserInfoError=_encodedUserInfoError;
@property(copy) NSData *encodedUserInfo; // @synthesize encodedUserInfo=_encodedUserInfo;
//@property(copy) NSData *streamsData; // @synthesize streamsData=_streamsData;
//@property(copy) NSURL *webpageURL; // @synthesize webpageURL=_webpageURL;
//@property(copy) NSString *teamIdentifier; // @synthesize teamIdentifier=_teamIdentifier;
//@property(copy) NSString *dynamicIdentifier; // @synthesize dynamicIdentifier=_dynamicIdentifier;
@property(copy) NSString *typeIdentifier; // @synthesize typeIdentifier=_typeIdentifier;
@property(copy) NSString *title; // @synthesize title=_title;
//@property(copy) NSDate *activityDate; // @synthesize activityDate=_activityDate;
//@property unsigned long long changeCount; // @synthesize changeCount=_changeCount;
//@property(copy) NSDictionary *options; // @synthesize options=_options;
//@property unsigned long long type; // @synthesize type=_type;
//@property(copy) NSUUID *uuid; // @synthesize uuid=_uuid;
//- (id)statusString;
//- (id)description;
//- (id)logString;
//- (id)optionalUserActivityData;
//- (id)secondaryUserActivityString;
//- (id)userActivityString;
//- (void)_createUserActivityStrings:(id)arg1 secondaryString:(id)arg2 optionalData:(id)arg3;
//- (void)dealloc;
//- (id)copyWithZone:(struct _NSZone *)arg1;
//- (void)encodeWithCoder:(id)arg1;
//- (id)initWithCoder:(id)arg1;

@end

@interface UAUserActivityManager : NSObject
{
    NSXPCConnection *_connection;
    NSObject<OS_dispatch_queue> *_serverQ;
    BOOL _connectionInitializationSucceeded;
    NSMapTable *_userActivitiesByUUID;
    BOOL _supportsActivityContinuation;
    BOOL _activityContinuationIsEnabled;
    BOOL _needToSendInitialMessage;
    NSUUID *_activeUserActivityUUID;
    NSMapTable *_activeUserActivitiesByUUID;
}

//+ (id)_determineMatchingApplicationBundleIdentfierWithOptionsForActivityType:(id)arg1 dynamicType:(id)arg2 kind:(unsigned long long)arg3 teamIdentifier:(id)arg4;
+ (id)defaultManager;
//+ (BOOL)userActivityContinuationSupported;
//+ (BOOL)shouldSupportActivityContinuation;
//@property BOOL needToSendInitialMessage; // @synthesize needToSendInitialMessage=_needToSendInitialMessage;
//@property(retain) NSMapTable *activeUserActivitiesByUUID; // @synthesize activeUserActivitiesByUUID=_activeUserActivitiesByUUID;
//@property(retain) NSMapTable *userActivitiesByUUID; // @synthesize userActivitiesByUUID=_userActivitiesByUUID;
//@property(readonly) NSObject<OS_dispatch_queue> *serverQ; // @synthesize serverQ=_serverQ;
//@property(copy) NSUUID *activeUserActivityUUID; // @synthesize activeUserActivityUUID=_activeUserActivityUUID;
//@property(readonly) BOOL supportsActivityContinuation; // @synthesize supportsActivityContinuation=_supportsActivityContinuation;
//- (id)activities;
//- (BOOL)hasUserActivityWithUUID:(id)arg1;
//- (void)pinUserActivity:(id)arg1 withCompletionHandler:(CDUnknownBlockType)arg2;
//- (BOOL)currentUserActivityUUIDWithOptions:(id)arg1 completionHandler:(CDUnknownBlockType)arg2;
//- (void)markUserActivityAsDirty:(id)arg1 forceImmediate:(BOOL)arg2;
//- (void)sendUserActivityInfoToLSUserActivityd:(id)arg1 makeCurrent:(BOOL)arg2;
//- (void)tellDaemonAboutNewLSUserActivity:(id)arg1;
//- (id)createByDecodingUserActivity:(id)arg1;
//- (id)encodeUserActivity:(id)arg1;
//- (void)didReceiveInputStreamWithUUID:(id)arg1 inputStream:(id)arg2 outputStream:(id)arg3;
//- (void)tellClientDebuggingEnabled:(BOOL)arg1 logFileHandle:(id)arg2;
//- (void)tellClientUserActivityItWasResumed:(id)arg1;
//- (void)askClientUserActivityToSave:(id)arg1 completionHandler:(CDUnknownBlockType)arg2;
//- (void)askClientUserActivityToSave:(id)arg1;
//- (id)activeActivitiesByPriority;
//- (id)_findUserActivityForUUID:(id)arg1;
//- (BOOL)userActivityIsActive:(id)arg1;
//- (void)makeInactive:(id)arg1;
//- (void)makeActive:(id)arg1;
//- (void)removeDynamicUserActivity:(id)arg1 matching:(id)arg2;
//- (void)addDynamicUserActivity:(id)arg1 matching:(id)arg2;
//- (void)removeUserActivity:(id)arg1;
//- (void)addUserActivity:(id)arg1;
//- (id)fetchUUID:(id)arg1 intervalToWaitForDocumentSynchonization:(double)arg2 withCompletionHandler:(CDUnknownBlockType)arg3;
//@property(readonly) BOOL activityContinuationIsEnabled;
//@property(readonly, retain) NSXPCConnection *connection;
//- (void)dealloc;
//- (id)initWithConnection:(id)arg1;
//- (id)init;
//- (void)sendInitialMessage:(BOOL)arg1;
//
//// Remaining properties
//@property(readonly, copy) NSString *debugDescription;
//@property(readonly, copy) NSString *description;
//@property(readonly) unsigned long long hash;
//@property(readonly) Class superclass;

@end
