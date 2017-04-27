

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from FireAlarm.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_cpp_h
#include "ndds/ndds_cpp.h"
#endif
#ifndef dds_c_log_impl_h              
#include "dds_c/dds_c_log_impl.h"                                
#endif        

#ifndef cdr_type_h
#include "cdr/cdr_type.h"
#endif    

#ifndef osapi_heap_h
#include "osapi/osapi_heap.h" 
#endif
#else
#include "ndds_standalone_type.h"
#endif

#include "FireAlarm.h"

/* ========================================================================= */
const char *FireAlarmTYPENAME = "FireAlarm";

DDS_TypeCode* FireAlarm_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode FireAlarm_g_tc_alarm_id_string = DDS_INITIALIZE_STRING_TYPECODE((10));
    static DDS_TypeCode_Member FireAlarm_g_tc_members[2]=
    {

        {
            (char *)"alarm_id",/* Member name */
            {
                0,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"state",/* Member name */
            {
                1,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode FireAlarm_g_tc =
    {{
            DDS_TK_STRUCT,/* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"FireAlarm", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            2, /* Number of members */
            FireAlarm_g_tc_members, /* Members */
            DDS_VM_NONE  /* Ignored */         
        }}; /* Type code for FireAlarm*/

    if (is_initialized) {
        return &FireAlarm_g_tc;
    }

    FireAlarm_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&FireAlarm_g_tc_alarm_id_string;

    FireAlarm_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

    is_initialized = RTI_TRUE;

    return &FireAlarm_g_tc;
}

RTIBool FireAlarm_initialize(
    FireAlarm* sample) {
    return FireAlarm_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool FireAlarm_initialize_ex(
    FireAlarm* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return FireAlarm_initialize_w_params(
        sample,&allocParams);

}

RTIBool FireAlarm_initialize_w_params(
    FireAlarm* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (allocParams) {} /* To avoid warnings */

    if (allocParams->allocate_memory){
        sample->alarm_id= DDS_String_alloc ((10));
        if (sample->alarm_id == NULL) {
            return RTI_FALSE;
        }

    } else {
        if (sample->alarm_id!= NULL) { 
            sample->alarm_id[0] = '\0';
        }
    }

    if (!RTICdrType_initBoolean(&sample->state)) {
        return RTI_FALSE;
    }     

    return RTI_TRUE;
}

void FireAlarm_finalize(
    FireAlarm* sample)
{

    FireAlarm_finalize_ex(sample,RTI_TRUE);
}

void FireAlarm_finalize_ex(
    FireAlarm* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    FireAlarm_finalize_w_params(
        sample,&deallocParams);
}

void FireAlarm_finalize_w_params(
    FireAlarm* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }
    if (deallocParams) {} /* To avoid warnings */

    if (sample->alarm_id != NULL) {
        DDS_String_free(sample->alarm_id);
        sample->alarm_id=NULL;

    }

}

void FireAlarm_finalize_optional_members(
    FireAlarm* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

}

RTIBool FireAlarm_copy(
    FireAlarm* dst,
    const FireAlarm* src)
{

    if (!RTICdrType_copyStringEx (
        &dst->alarm_id, src->alarm_id, 
        (10) + 1, RTI_FALSE)){
        return RTI_FALSE;
    }
    if (!RTICdrType_copyBoolean (
        &dst->state, &src->state)) { 
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'FireAlarm' sequence class.
*/
#define T FireAlarm
#define TSeq FireAlarmSeq
#define T_initialize_w_params FireAlarm_initialize_w_params
#define T_finalize_w_params   FireAlarm_finalize_w_params
#define T_copy       FireAlarm_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#include "dds_cpp_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params
#undef T_initialize_w_params
#undef TSeq
#undef T

