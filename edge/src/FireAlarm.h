

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from FireAlarm.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef FireAlarm_1522294833_h
#define FireAlarm_1522294833_h

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_cpp_h
#include "ndds/ndds_cpp.h"
#endif
#else
#include "ndds_standalone_type.h"
#endif

extern "C" {

    extern const char *FireAlarmTYPENAME;

}

struct FireAlarmSeq;
#ifndef NDDS_STANDALONE_TYPE
class FireAlarmTypeSupport;
class FireAlarmDataWriter;
class FireAlarmDataReader;
#endif

class FireAlarm 
{
  public:
    typedef struct FireAlarmSeq Seq;
    #ifndef NDDS_STANDALONE_TYPE
    typedef FireAlarmTypeSupport TypeSupport;
    typedef FireAlarmDataWriter DataWriter;
    typedef FireAlarmDataReader DataReader;
    #endif

    DDS_Char *   alarm_id ;
    DDS_Boolean   state ;

};
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

NDDSUSERDllExport DDS_TypeCode* FireAlarm_get_typecode(void); /* Type code */

DDS_SEQUENCE(FireAlarmSeq, FireAlarm);                                        

NDDSUSERDllExport
RTIBool FireAlarm_initialize(
    FireAlarm* self);

NDDSUSERDllExport
RTIBool FireAlarm_initialize_ex(
    FireAlarm* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool FireAlarm_initialize_w_params(
    FireAlarm* self,
    const struct DDS_TypeAllocationParams_t * allocParams);        

NDDSUSERDllExport
void FireAlarm_finalize(
    FireAlarm* self);

NDDSUSERDllExport
void FireAlarm_finalize_ex(
    FireAlarm* self,RTIBool deletePointers);

NDDSUSERDllExport
void FireAlarm_finalize_w_params(
    FireAlarm* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void FireAlarm_finalize_optional_members(
    FireAlarm* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool FireAlarm_copy(
    FireAlarm* dst,
    const FireAlarm* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* FireAlarm */

