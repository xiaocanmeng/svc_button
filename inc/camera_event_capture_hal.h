/*
 * @copyright Copyright (c) 2021-     TOYOTA MOTOR CORPORATION.
 * @copyright Copyright (c) 2022-2023 Woven by Toyota, Inc.
 */

#ifndef INCLUDE_CAMERA_EVENT_CAPTURE_HAL_H_
#define INCLUDE_CAMERA_EVENT_CAPTURE_HAL_H_

/*----------------------------------------------------------------------------*/
/* include                                                                    */
/*----------------------------------------------------------------------------*/
#include <cstdint>

/*----------------------------------------------------------------------------*/
/* namespace                                                                  */
/*----------------------------------------------------------------------------*/
namespace cockpit {
namespace hal {
namespace camera_event_capture_hal {

/*----------------------------------------------------------------------------*/
/* enum class                                                                 */
/*----------------------------------------------------------------------------*/

/**
 * API block settings
 */
enum class ApiFlags : uint8_t {
  kBlock = 0,
  kNonBlock,
};

/**
 * Return values
 */
enum class Result : int32_t {
  kOK = 0,
  kErrInternalLib,
  kErrInternalImpl,
  kErrArgument,
  kErrCommunication,
  kErrHW,
  kErrSystem,
  kErrAi,
  kErrHalStatus,
};

/**
 * Control
 */
enum class Control : uint8_t {
  kStart = 0,
  kStop,
};

/**
 * ControlCommand
 */
enum class ControlCommand : uint8_t {
  kInit = 0,
  kStart,
  kStop,
  kDeinit,
  kCommSet,
  kClose,
};

/**
 * RecordType
 */
enum class RecordType : uint8_t {
  kContinuous = 0,
  kManual,
  kEvent,
  kParking,
  kCharging,
};

/**
 * VideoType
 */
enum class VideoType : uint8_t {
  kVideo = 0,
  kStillImage,
};

/**
 * AiDataType
 */
enum class AiDataType : uint8_t {
  kRecord = 0,
  kRealtime,
};

/**
 * CalculateOperation
 */
enum class CalculateOperation : uint8_t {
  kExecute = 0,
  kStart,
  kEnd,
};

/**
 * ProtectOperation
 */
enum class ProtectOperation : uint8_t {
  kRunning = 0,
  kStart,
  kEnd,
  kRelease,
};

/**
 * Specify
 */
enum class Specify : uint8_t {
  kEventSignalReceptionTime = 0,
  kSpecifiedTime,
  kNotSpecified,
  kLastRecordingStart,
};

/**
 * FlagValue
 */
enum class FlagValue : uint8_t {
  kFlagOff = 0,
  kFlagOn,
};

/**
 * HalStatus
 */
enum class HalStatus : uint8_t {
  kAvailable = 0,
  kNotAvailable,
  kMemoryClear,
};

/**
 * CameraStatus
 */
enum class CameraStatus : uint8_t {
  kRecordStart = 0,
  kRecordEnd,
};

/**
 * ErrorStatus
 */
enum class ErrorStatus : uint8_t {
  kNoError = 0,
  kError,
};

/**
 * ErrorCode
 */
enum class ErrorCode : uint32_t {
  kNoError = 0,
  kInternalImpl,
  kHW,
  kParamError,
  kInsufficientStorage,
  kFileReadError,
  kFileWriteError,
  kFileOtherError,
  kMemoryClearError,
  kHalStatusError,
  kFileRemoveError,
  kAiModelLoadFailure = 1001,
  kAiConfigLoadFailure,
  kAiConfigValueFailure,
  kAiVideoInterruption,
  kAiVideoBlackPainting,
  kAiImageDataAbnormality,
  kAiInputDataAcquisitionError,
  kAiConversionErrorTimeout,
  kAiConversionErrorDataError,
  kAiEngineTimeout,
  kAiEngineDataError,
  kAiOutputDataError,
  kAiCoordinateValueOutOfRange,
  kAiLackOfResources,
  kProtectUpperLimit = 3001,
  kProtectEventBlocking,
  kProtectFileNotExist,
  kProtectErrEventId,
  kGetImageDirectoryAccessError = 4001,
  kGetImageFileNotExist,
  kGetImageCameraOff,
  kGetImageRecordingOff,
  kGetImagePartMissing,
  kImageFileDuplicatesError,
  kImageFileInterruptionError,
  kGetImageDisruption,
  kRemoveFileNotExist,
};

/**
 * UploadKind
 */
enum class UploadKind : uint8_t {
  kVideo = 0,
  kProfile,
};

/**
 * CameraImageType
 */
enum class CameraImageType : uint8_t {
  kNone = 0,
  kFront,
  kRear,
  kBGM,
  kSurround,
  kInCabin,
};

/**
 * ProtectType
 */
enum class ProtectType : uint8_t {
  kNone = 0,
  kUserProtect,
  kSystemProtect1,
  kSystemProtect2,
  kSystemProtect3,
  kSystemProtect4,
  kSystemProtect5,
  kSystemProtect6,
  kSystemProtect7,
  kSystemProtect8,
  kSystemProtect9,
};

/**
 * TransferStatus
 */
enum class TransferStatus : uint8_t {
  kNotForward = 0,
  kForward,
};

/**
 * ProtectStatus
 */
enum class ProtectStatus : uint8_t {
  kProtectionEnd = 0,
  kFileClose,
  kUnprotect,
};

/**
 * MethodType
 */
enum class MethodType : uint16_t {
  kResUploadData = 0,
  kResThumbnailFileList,
  kGetAiModel,
  kSetProfileInfo,
};

/**
 * AiModelPurpose
 */
enum class AiModelPurpose : uint8_t {
  kObject = 0,
  kCharacter,
  kMax,
};

/**
 * ClearMode
 */
enum class ClearMode : uint8_t {
  kImageFileClear = 0,
  kInitClear,
};

/**
 * BitRate
 */
enum class BitRate : uint8_t {
  k1Mbps = 0,
  k2Mbps,
  k3Mbps,
  k4Mbps,
  k5Mbps,
  k6Mbps,
  k8Mbps,
};

/**
 * Audio
 */
enum class Audio : uint8_t {
  kOff = 0,
  kOnParking,
  kOn,
};

/**
 * TransferPriority
 */
enum class TransferPriority : uint8_t {
  kHigh = 0,
  kLow,
};

/*----------------------------------------------------------------------------*/
/* struct                                                                     */
/*----------------------------------------------------------------------------*/
/**
 * Time
 */
struct Time {
  // 2010+xx * Year is the difference from 2010 AD
  uint8_t year;
  // Month, 1-12
  uint8_t month;
  // Day, 1-31
  uint8_t day;
  // Hour, 0-23
  uint8_t hour;
  // Minute, 0-59
  uint8_t min;
  // Second, 0-59
  uint8_t sec;
  // Reserve
  uint8_t reserved[2];
};

/**
 * ControlInfo
 */
struct ControlInfo {
  // Command
  ControlCommand command;
  // Reserve
  uint8_t reserved;
  // timeout
  uint16_t timeout;
};

/**
 * ThumbnailFileInfo
 */
struct ThumbnailFileInfo {
  // Thumbnail ID
  uint32_t thumbnail_id;
  // File start time
  Time start_time;
  // Event occurrence time
  Time event_time;
  // Configuration of camera video recording
  CameraImageType camera_type;
  // Recording type(Can not multiple designation)
  RecordType record_type;
  // Protect Type
  ProtectType protect_type;
  // IGR state
  FlagValue igr_status;
  // transfer state
  TransferStatus transfer_status;
  // Reserve
  uint8_t reserved[3];
  // longitude(10^-7degree(WGS-84))
  int32_t longitude;
  // latitude(10^-7degree(WGS-84))
  int32_t latitude;
  // IGR-ON,IGR-OFF counter (used for video group flag processing)
  uint32_t igr_counter;
};

/**
 * AiModel
 */
struct AiModel {
  // AI model ID
  uint8_t aimodel_id;
  // Detection class num
  uint8_t class_num;
  // Reserve
  uint8_t reserved[2];
  // Detection class name
  uint8_t class_name[64][32];
};

/**
 * AiCalculateCondition
 */
struct AiCalculateCondition {
  // Calculation ID
  uint32_t calculation_id;
  // AI model ID
  uint8_t aimodel_id[static_cast<uint8_t>(AiModelPurpose::kMax)];
  // Input data type
  AiDataType data_type;
  // Threshold for remove overlapping
  uint8_t remove_threshold;
};

/**
 * AiDetectClassCondition
 */
struct AiDetectClassCondition {
  // Threshold for detecting objects
  uint8_t detect_threshold;
  // Maximum number of objects detections
  uint8_t detect_num;
  // Threshold for recognize character
  uint8_t recognize_threshold;
  // Reserve
  uint8_t reserved;
};

/**
 * AiCalculateData
 */
struct AiCalculateData {
  // ID that identifies the operation you want to perform an operation
  CalculateOperation operation;
  // Whether to specify the calculation start reference point
  uint8_t start_specify;
  // Whether to specify the calculation end reference point
  uint8_t end_specify;
  // Reserve
  uint8_t reserved;
  // Calculation start reference point (time)
  Time start_time;
  // Calculation end reference point (time)
  Time end_time;
  // File ID or Target camera
  uint32_t target;
  // Frame rate.(fps)
  uint32_t fps;
};

/**
 * TimePeriod
 */
struct TimePeriod {
  // Start time
  Time start;
  // End time
  Time end;
};

/**
 * ProtectInfo
 */
struct ProtectInfo {
  // Operation Type.
  ProtectOperation operation;
  // protect_priority
  uint8_t protect_priority;
  // ID that identifies the received event.
  uint16_t event_id;
  // Collection condition ID when the event occurs
  uint16_t correct_id;
  // Whether to specify the event start reference point.
  Specify start_specify;
  // Whether to specify the event termination reference point.
  Specify end_specify;
  // Protection Target camera.
  uint32_t camera_type;
  // Event occurrence time (event received time).
  Time event_time;
  // Event start reference point (time).
  Time start_time;
  // End-of-event reference point (time).
  Time end_time;
  // Event protection time (before).
  uint8_t before_time;
  // Event protection time (after).
  uint8_t after_time;
  // Reserve
  uint8_t reserved[2];
};

/**
 * Configuration
 */
struct Configuration {
  // Service active configuration
  uint16_t service_active;
  // Configuration changed by user
  uint16_t record_configuration;
  // Configuration changed by user(audio)
  Audio audio_configuration;
  // Server automatic transfer image quality setting
  BitRate bitrate_server;
  // Remote car monitoring image quality setting
  BitRate bitrate_remote;
  // Reserve
  uint8_t reserved;
};

/**
 * StatusInfo
 */
struct StatusInfo {
  // HAL availability
  HalStatus hal_status;
  // Camera status
  CameraStatus camera_status;
  // Existence of camera registration history.
  uint8_t camera_registration;
  // Device abnormal status.
  uint8_t device_error;
  // Camera abnormal status.
  uint32_t camera_error;
  // Camera abnormal recovery failure status
  uint32_t recovery_error;
};

/**
 * EventOccurenceId
 */
struct EventOccurenceId {
  // Time
  Time event_time;
  // Event ID
  uint16_t event_id;
  // Reserve
  uint8_t reserved[2];
};

/**
 * UploadImageFile
 */
struct UploadImageFile {
  // Event occurrence ID
  EventOccurenceId event_occurence_id;
  // Start time
  Time start_time;
  // End time
  Time end_time;
  // Video type
  VideoType video_type;
  // Whether to include audio or not
  FlagValue include_audio;
  // Still image thinning
  uint8_t image_thinning;
  // Image type
  CameraImageType video_kind;
  // Providing profile information
  FlagValue profile_provision;
  // Concealment setting
  FlagValue concealment;
  // Specify time
  FlagValue specify_time;
  // Reserve
  uint8_t reserved;
};

/**
 * UploadDataCondition
 */
struct UploadDataCondition {
  // upload ID
  uint32_t upload_id;
  // process status
  Control control;
  // data transmission cycle
  uint8_t upload_cycle;
  // camera image type
  CameraImageType camera_type;
  // framerate
  uint8_t fps;
  // Concealment setting
  FlagValue concealment;
  // Whether to include audio or not
  FlagValue include_audio;
  // Reserve
  uint8_t reserved[2];
};

/**
 * ConcealmentCondition
 */
struct ConcealmentCondition {
  // AI model ID
  uint8_t aimodel_id;
  // Threshold for remove overlapping
  uint8_t remove_threshold;
  // Reserve
  uint8_t reserved[2];
};

/**
 * ConcealmentDetectClassCondition
 */
struct ConcealmentDetectClassCondition {
  // Threshold for detecting objects
  uint8_t detect_threshold;
  // Maximum number of objects detections
  uint8_t detect_num;
  // Reserve
  uint8_t reserved[2];
};

/**
 * ThumbnailInfo
 */
struct ThumbnailInfo {
  // Thumbnail ID
  uint32_t thumbnail_id;
  // Protection type
  ProtectType protect_type;
  // Transfer status
  TransferStatus transfer_status;
  // Reserve
  uint8_t reserved[2];
};

/**
 * ProtectStatusInfo
 */
struct ProtectStatusInfo {
  // Protect status
  ProtectStatus protect_status;
  // Reserve
  uint8_t reserved;
  // Event ID
  uint16_t event_id;
  // Event occurrence time
  Time event_time;
  // Event start time
  Time start_time;
  // Event end time
  Time end_time;
};

/**
 * ThumbnailIdInfo
 */
struct ThumbnailIdInfo {
  // Thumbnail file ID
  uint32_t thumbnail_id;
  // Number of video file ID
  uint32_t file_num;
  // Video file ID
  uint32_t file_id[3];
};

/**
 * ImageFileResData
 */
struct ImageFileResData {
  // File ID
  uint32_t file_id;
  // File name
  uint8_t file_name[26];
  // Reserve
  uint8_t reserved[2];
};

/**
 * RecvDataUploadData
 */
struct RecvDataUploadData {
  // Upload stop
  FlagValue upload_stop;
  // Error status
  ErrorStatus error_status;
  // Reserve
  uint8_t reserved[2];
  // Upload ID
  uint32_t upload_id;
  // Data size
  uint32_t size;
  // Error code
  ErrorCode error_code;
};

/**
 * RecvDataThumbnailFileList
 */
struct RecvDataThumbnailFileList {
  // Error status
  ErrorStatus error_status;
  // Reserve
  uint8_t reserved[3];
  // Number of video files (n)
  uint32_t file_num;
  // Error code
  ErrorCode error_code;
};

/**
 * RecvDataAiModel
 */
struct RecvDataAiModel {
  // Number of AI model
  uint32_t num;
  // Return values
  Result result;
};

/**
 * SetDataProfileInfo
 */
struct SetDataProfileInfo {
  // profile information size
  uint32_t profilesize;
  // API block settings
  ApiFlags apiflags;
  // Reserve
  uint8_t reserved[3];
};

/**
 * CecHalBin
 */
struct CecHalBin {
  // Receiving function type
  MethodType method_type;
  // Socket communication management ID
  uint16_t id;
  // Transmit data buffer
  union RecvData {
    // Transmit data buffer(ResUploadData)
    RecvDataUploadData res_upload_data;
    // Transmit data buffer(ResThumbnailFileList)
    RecvDataThumbnailFileList res_thumbnail_file_list;
    // Transmit data buffer(GetAiModel)
    RecvDataAiModel res_ai_model;
    // Transmit data buffer(SetProfileInfo)
    SetDataProfileInfo set_profile_info;
  } recv_data;
};

// Callback function(ResThumbnailFileList)
using FuncPointerResThumbnailFileList = void (*)(uint32_t,
                                                 const ThumbnailFileInfo*,
                                                 ErrorStatus, ErrorCode);
// Callback function(ResImageFile)
using FuncPointerResImageFile = void (*)(uint32_t,
                                         const ImageFileResData*, ErrorStatus,
                                         ErrorCode);
// Callback function(ResThumbnailFile)
using FuncPointerResThumbnailFile = void (*)(FlagValue, uint32_t,
                                             const uint8_t*, ErrorStatus,
                                             ErrorCode);
// Callback function(ResImageFileInfo)
using FuncPointerResImageFileInfo = void (*)(uint32_t, uint32_t,
                                             const uint32_t*, ErrorStatus,
                                             ErrorCode);
// Callback function(ResAiCalculate)
using FuncPointerResAiCalculate = void (*)(uint32_t, uint32_t, const uint8_t*,
                                           uint32_t, FlagValue, ErrorStatus,
                                           ErrorCode);
// Callback function(ResUploadData)
using FuncPointerResUploadData = void (*)(uint32_t, uint32_t, const uint8_t*,
                                          FlagValue, ErrorStatus, ErrorCode);
// Callback function(ResUploadImageFile)
using FuncPointerResUploadImageFile = void (*)(const EventOccurenceId&,
                                               const uint8_t*,
                                               UploadKind, FlagValue, uint32_t,
                                               const TimePeriod*, ErrorStatus,
                                               ErrorCode);
// Callback function(ResProtect)
using FuncPointerResProtect = void (*)(uint32_t, const ProtectStatusInfo&,
                                       uint32_t, uint32_t, const uint32_t*,
                                       const uint32_t*, ErrorStatus, ErrorCode);
// Callback function(ResMemoryClear)
using FuncPointerResMemoryClear = void (*)(ErrorStatus, ErrorCode);
// Callback function(ResRemoveFile)
using FuncPointerResRemoveFile = void(*)(uint32_t, const ThumbnailIdInfo*,
                                         ErrorStatus, ErrorCode);
// Callback function(NotifyStatus)
using FuncPointerNotifyStatus = void (*)(const StatusInfo&);

/**
 * Callbacks
 */
struct Callbacks {
  // Callback function(ResThumbnailFileList)
  FuncPointerResThumbnailFileList res_thumbnail_file_list;
  // Callback function(ResImageFile)
  FuncPointerResImageFile res_image_file;
  // Callback function(ResThumbnailFile)
  FuncPointerResThumbnailFile res_thumbnail_file;
  // Callback function(ResImageFileInfo)
  FuncPointerResImageFileInfo res_image_file_info;
  // Callback function(ResAiCalculate)
  FuncPointerResAiCalculate res_ai_calculate;
  // Callback function(ResUploadData)
  FuncPointerResUploadData res_upload_data;
  // Callback function(ResUploadImageFile)
  FuncPointerResUploadImageFile res_upload_image_file;
  // Callback function(ResProtect)
  FuncPointerResProtect res_protect;
  // Callback function(ResMemoryClear)
  FuncPointerResMemoryClear res_memory_clear;
  // Callback function(ResRemoveFile)
  FuncPointerResRemoveFile res_remove_file;
  // Callback function(NotifyStatus)
  FuncPointerNotifyStatus notify_status;
};

/*----------------------------------------------------------------------------*/
/* prototype                                                                  */
/*----------------------------------------------------------------------------*/

/**
 * Brief     : Requests check of launch, start of recording, stop of recording,
 *             initialize , connect communication, and disconnect communication
 *             to HAL.
 * Parameter : [I] control  : Control the CamEvtCapfunction.
 * Parameter : [I] apiflags : API block settings
 * Return    : Value from Result enum
 */
Result SetControl(const ControlInfo& control, ApiFlags apiflags);

/**
 * Brief     : Configure the function, enable/disable the camera for HAL.
 * Parameter : [I] configuration  : Function presence/absence,
 *                                  camera enable/disable
 * Parameter : [I] apiflags : API block settings
 * Return    : Value from Result enum
 */
Result SetConfiguration(const Configuration& configuration, ApiFlags apiflags);

/**
 * Brief     : Get the configuration, EIM number and Vide board version
 *             currently held by HAL and below.
 * Parameter : [O] configuration : Configuration
 * Parameter : [O] rear_camera_id : Rear camera identification symbol
 * Parameter : [O] video_board_version : Video board version
 * Parameter : [I/O] video_board_version_size : Size of Video board version
 * Return    : Value from Result enum
 */
Result GetConfiguration(Configuration* configuration, uint8_t* rear_camera_id,
                        void* video_board_version,
                        uint32_t* video_board_version_size);

/**
 * Brief     : Set the vehicle information(location information etc.)
 *             to be added to the video file.
 * Parameter : [I] vehicleinfo : vehicle information
 * Parameter : [I] vehiclesize : vehicle information size
 * Parameter : [I] apiflags : API block settings
 * Return    : Value from Result enum
 */
Result SetVehicleInfo(const uint8_t* vehicleinfo, uint32_t vehiclesize,
                      ApiFlags apiflags);

/**
 * Brief     : Set the profile information to be added to the video file.
 * Parameter : [I] profileinfo : profile information
 * Parameter : [I] profilesize : profile information size
 * Parameter : [I] apiflags : API block settings
 * Return    : Value from Result enum
 */
Result SetProfileInfo(const uint8_t* profileinfo, uint32_t profilesize,
                      ApiFlags apiflags);

/**
 * Brief     : Get the list of AI models currently held by HAL and below.
 * Parameter : [I/O] num : Number of AI model
 * Parameter : [O] aimodel : Configuration of AI model
 * Return    : Value from Result enum
 */
Result GetAiModel(uint32_t* num, AiModel* aimodel);

/**
 * Brief     : Get Status under CamEvtCap HAL
 *             (For example : function state, err state)
 * Parameter : [O] status : Various states below CamEvtCap HAL
 * Return    : Value from Result enum
 */
Result GetStatus(StatusInfo* status);

/**
 * Brief     : Notify HAL of device information from a higher-level service.
 * Parameter : [I] camera_error : Camera abnormality detected by other ECU
 * Parameter : [I] camera_connect_status : Camera connection status
 * Parameter : [I] part_connect_status : Parts connection status
 * Parameter : [I] device_error : Device error(upper service detection)
 * Parameter : [I] apiflags : API block settings
 * Return    : Value from Result enum
 */
Result SetDeviceInfo(uint32_t camera_error, uint32_t camera_connect_status,
                     uint32_t part_connect_status, uint8_t device_error,
                     ApiFlags apiflags);

/**
 * Brief     : Returns the number of shots that can be taken below HAL.
 * Parameter : [O] num : Number of shots that can be taken
 * Return    : Value from Result enum
 */
Result GetShootableNum(uint32_t* num);

/**
 * Brief     : Set the transfer status from the upper service to HAL.
 * Parameter : [I] thumbnail_Info : Thumbnail information
 * Parameter : [I] thumbnail_num : Thumbnail num
 * Return    : Value from Result enum
 */
Result SetThumbnailInfo(const ThumbnailInfo* thumbnail_Info,
                        uint32_t thumbnail_num);

/**
 * Brief     : Acquire the thumbnail file ID and video file ID associated
 *             with the event ID.
 * Parameter : [I] event_id : Event id
 * Parameter : [I] event_time : Event occurrence time
 * Parameter : [I/O] thumbnail_num : Number of thumbnail files
 * Parameter : [I/O] image_num : Number of video files
 * Parameter : [O] thumbnail_id : Thumbnail ID
 * Parameter : [O] file_id : Video file ID
 * Return    : Value from Result enum
 */
Result GetImageFileId(uint16_t event_id, const Time& event_time,
                      uint32_t* thumbnail_num, uint32_t* image_num,
                      uint32_t* thumbnail_id, uint32_t* file_id);

/**
 * Brief     : Requests a list of all thumbnail files held by the image board.
 * Parameter : [I] camera_type : Camera type
 * Parameter : [I] record_type : Record type
 * Return    : Value from Result enum
 */
Result ReqThumbnailFileList(uint8_t camera_type, uint8_t record_type);

/**
 * Brief     : Requests the video file data held by HAL and below.
 * Parameter : [I] copy_dir : Name of the directory containing
 *                            the video file (128 bytes)
 * Parameter : [I] file_num : Number of requested files
 * Parameter : [I] file_id : Array of file IDs
 *                           for the number of requested files
 * Parameter : [I] priority : Transfer priority
 * Return    : Value from Result enum
 */
Result ReqImageFile(const uint8_t* copy_dir, uint32_t file_num,
                    const uint32_t* file_id, TransferPriority priority);

/**
 * Brief     : Requests the thumbnail file data held by HAL and below.
 * Parameter : [I] copy_dir : Name of the directory containing
 *                            the thumbnail file (128 bytes)
 * Parameter : [I] file_num : Number of requested thumbnail files
 * Parameter : [I] file_id : Array of thumbnail file IDs
 *                           for the number of requested thumbnail files
 * Return    : Value from Result enum
 */
Result ReqThumbnailFile(const uint8_t* copy_dir, uint32_t file_num,
                        const uint32_t* file_id);

/**
 * Brief     : Acquire the video file associated with the thumbnail file ID
 *             held on the image board side.
 * Parameter : [I] thumbnail_id : thumbnail file ID
 * Return    : Value from Result enum
 */
Result ReqImageFileInfo(uint32_t thumbnail_id);

/**
 * Brief     : Specify the AI model, calculation conditions and conversion
 *             conditions, and obtain the inference result corrected and
 *             converted from calculation processing result (feature map).
 * Parameter : [I] aicalculate_condition : AI calculation information
 *                             (Calculation ID, AI model,
 *                              calculation conditions, conversion conditions)
 * Parameter : [I] class_num : Number of detection class
 * Parameter : [I] class_condition : Conversion conditions of detection calss.
 *                                   Specify for each detection calss.
 * Parameter : [I] data : Data to be calculated by AI
 * Return    : Value from Result enum
 */
Result ReqAiCalculate(const AiCalculateCondition& aicalculate_condition,
                      uint8_t class_num,
                      const AiDetectClassCondition* class_condition,
                      const AiCalculateData& data);

/**
 * Brief     : Upload real time video data.
 * Parameter : [I] upload_data_condition : Upload data condition
 * Parameter : [I] concealment_condition : Concealment condition
 * Parameter : [I] class_num : Number of detection class
 * Parameter : [I] class_condition : Conversion conditions of detection calss.
                                     Specify for each detection calss
 * Return    : Value from Result enum
 */
Result ReqUploadData(const UploadDataCondition& upload_data_condition,
                     const ConcealmentCondition& concealment_condition,
                     uint8_t class_num,
                     const ConcealmentDetectClassCondition* class_condition);

/**
 * Brief     : Get the recorded video data, profile.
 * Parameter : [I] image_file : Server upload parameters
 * Parameter : [I] copy_dir : File storage directory name (128 bytes)
 * Parameter : [I] concealment_condition : Concealment condition
 * Parameter : [I] class_num : Number of detection class
 * Parameter : [I] class_condition : Conversion conditions of detection calss.
                                     Specify for each detection calss
 * Return    : Value from Result enum
 */
Result ReqUploadImageFile(
    const UploadImageFile& image_file, const uint8_t* copy_dir,
    const ConcealmentCondition& concealment_condition, uint8_t class_num,
    const ConcealmentDetectClassCondition* class_condition);

/**
 * Brief     : Protects video files for a specified period of time for the Event
 *             that occurred.
 * Parameter : [I] protect_id : Protection ID
 * Parameter : [I] protect_info : Conditions for video files to be protected
 *                       (event, time of occurrence, start/end time of storage)
 * Return    : Value from Result enum
 */
Result ReqProtect(uint32_t protect_id, const ProtectInfo& protect_info);

/**
 * Brief     : Perform memory clear processing.
 * Parameter : [I] clear_mode :Clear mode
 * Return    : Value from Result enum
 */
Result ReqMemoryClear(ClearMode clear_mode);

/**
 * Brief     : Remove the thumbnail file and video file data held by HAL and
 *             below.
 * Parameter : [I] thumbnail_num : Number of requested thumbnail files
 * Parameter : [I] thumbnail_id : Array of thumbnail file IDs for the number of
 *                                requested thumbnail files
 * Return    : Value from Result enum
 */
Result ReqRemoveFile (uint32_t thumbnail_num, const uint32_t* thumbnail_id);

/**
 * Brief     : Register callback functions for response
 *             from CamEvtCap HAL to service.
 * Parameter : [I] callbacks : List of callback functions
 * Return    : Value from Result enum
 */
Result RegisterCallbacks(const Callbacks& callbacks);

/**
 * Brief     : Cancel callback functions for response
 *             from CamEvtCap HAL to service
 * Return    : Value from Result enum
 */
Result UnRegisterCallbacks();

}  // namespace camera_event_capture_hal
}  // namespace hal
}  // namespace cockpit

#endif  // INCLUDE_CAMERA_EVENT_CAPTURE_HAL_H_
