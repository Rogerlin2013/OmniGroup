// Copyright 2012-2016 Omni Development, Inc. All rights reserved.
//
// This software may only be used and reproduced according to the
// terms in the file OmniSourceLicense.html, which should be
// distributed with this project and can also be found at
// <http://www.omnigroup.com/developer/sourcecode/sourcelicense/>.
//
// $Id$

#import <Foundation/NSObject.h>
#import <OmniBase/macros.h>

NS_ASSUME_NONNULL_BEGIN

/*
 This allows classes to form collections of weak references. OS X 10.8 adds weak support for NSMapTable, but this class will work on 10.7 and will support other collections. Note that -hash and -isEqual: are not currently bridged to the contained object (and we'd need to cache the hash in case the weak object reference was nullified). For now we just get the default -hash (pointer based) so this is just useful for arrays and dictionary values.
 */
@interface OFWeakReference OB_GENERIC1(ObjectType) : NSObject

- initWithObject:(OB_GENERIC_ARG(ObjectType))object;
- (BOOL)referencesObject:(void *)objectPointer;

#if OB_ARC
@property(nonatomic,nullable,weak) OB_GENERIC_ARG(ObjectType) object;
#else
@property(nonatomic,nullable,assign) OB_GENERIC_ARG(ObjectType) object;
#endif

// Conveniences that do the common work of removing references that have been nullified, and ensuring that any object is added only once.
+ (void)add:(ObjectType)object toReferences:(NSMutableArray <OFWeakReference <ObjectType> *> *)references;
+ (void)remove:(ObjectType)object fromReferences:(NSMutableArray <OFWeakReference <ObjectType> *> *)references;
+ (void)forEachReference:(NSMutableArray <OFWeakReference <ObjectType> *> *)references perform:(void (^)(ObjectType))action;

@end

NS_ASSUME_NONNULL_END

