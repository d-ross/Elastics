//
//  Account.h
//  ElasticsPreferences
//
//  Created by Dmitri Goutnik on 7/26/11.
//  Copyright 2011 Tundra Bot. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Security/Security.h>

// Notication set by Account when account data changes
extern NSString *const kAccountDidChangeNotification;

@interface Account : NSObject {
@private
	NSInteger			_accountId;
	NSString			*_name;
	NSString			*_accessKeyID;
	NSString			*_secretAccessKey;
    NSInteger           _defaultRegion;
	NSString			*_sshPrivateKeyFile;
	NSString			*_sshUserName;
	NSUInteger			_sshPort;
    NSString            *_sshOptions;
	SecKeychainItemRef	_itemRef;
}

+ (id)accountWithID:(NSInteger)accountId
               name:(NSString *)name
        accessKeyId:(NSString *)accessKeyId
    secretAccessKey:(NSString *)secretAccessKey
  sshPrivateKeyFile:(NSString *)sshPrivateKeyFile
        sshUserName:(NSString *)sshUserName
            sshPort:(NSUInteger)sshPort
         sshOptions:(NSString *)sshOptions;

+ (id)accountWithKeychainItemRef:(SecKeychainItemRef)itemRef;

- (id)initWithID:(NSInteger)accountId
            name:(NSString *)name
     accessKeyId:(NSString *)accessKeyId
 secretAccessKey:(NSString *)secretAccessKey
sshPrivateKeyFile:(NSString *)sshPrivateKeyFile
     sshUserName:(NSString *)sshUserName
         sshPort:(NSUInteger)sshPort
      sshOptions:(NSString *)sshOptions;

- (id)initWithKeychainItemRef:(SecKeychainItemRef)itemRef;

- (OSStatus)save;
- (OSStatus)remove;

@property (nonatomic, readonly) NSInteger accountId;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *accessKeyID;
@property (nonatomic, copy) NSString *secretAccessKey;
@property (nonatomic, assign) NSInteger defaultRegion;
@property (nonatomic, copy) NSString *sshPrivateKeyFile;
@property (nonatomic, copy) NSString *sshUserName;
@property (nonatomic, assign) NSUInteger sshPort;
@property (nonatomic, copy) NSString *sshOptions;
@property (nonatomic, readonly) SecKeychainItemRef itemRef;

@property (nonatomic, readonly) NSString *title;

@end
