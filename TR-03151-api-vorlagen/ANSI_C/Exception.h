/**
 * This header file defines error codes that are returned in form of return values by the
 * functions of the Secure Element API(SE API) in a particular case of failure
 */

/**
 * The return value ERROR_RETRIEVE_LOG_MESSAGE_FAILED indicates that
 * the retrieving of the log message parts that have been
 * created by Secure Element most recently failed
 */
#define ERROR_RETRIEVE_LOG_MESSAGE_FAILED -5001

/**
 * The return value ERROR_STORAGE_FAILURE indicates that
 * storing of the log message in the storage failed
 */
#define ERROR_STORAGE_FAILURE -5002

/**
 * The return value ERROR_UPDATE_TIME_FAILED indicates that
 * the execution of the Secure Element functionality for setting the time failed
 */
#define ERROR_UPDATE_TIME_FAILED -5003

/**
 * The return value ERROR_PARAMETER_MISMATCH indicates that
 * there is a mismatch regarding the particular parameters
 * that have been provided in the context of the export of stored data
 */
#define ERROR_PARAMETER_MISMATCH -5004

/**
 * The return value ERROR_ID_NOT_FOUND indicates that
 * no data has been found for the provided clientID
 * in the context of the export of stored data
 */
#define ERROR_ID_NOT_FOUND -5005

/**
 * The return value ERROR_TRANSACTION_NUMBER_NOT_FOUND indicates that
 * no data has been found for the provided transaction number(s)
 * in the context of the export of stored data
 */
#define ERROR_TRANSACTION_NUMBER_NOT_FOUND -5006

/**
 * The return value ERROR_NO_DATA_AVAILABLE indicates that
 * no data has been found for the provided selection
 * in the context of the export of stored data
 */
#define ERROR_NO_DATA_AVAILABLE -5007

/**
 * The return value ERROR_TOO_MANY_RECORDS indicates that
 * the amount of requested records exceeds the passed value for the maximum number of records
 * in the context of the export of stored data
 */
#define ERROR_TOO_MANY_RECORDS -5008

/**
 * The return value ERROR_START_TRANSACTION_FAILED indicates that
 * the execution of the Secure Element functionality to start a transaction failed
 */
#define ERROR_START_TRANSACTION_FAILED -5009

/**
 * The return value ERROR_UPDATE_TRANSACTION_FAILED indicates that
 * the execution of the Secure Element functionality for updating a transaction failed
 */
#define ERROR_UPDATE_TRANSACTION_FAILED -5010

/**
 * The return value ERROR_FINISH_TRANSACTION_FAILED indicates that
 * the execution of the Secure Element functionality for finishing a transaction failed
 */
#define ERROR_FINISH_TRANSACTION_FAILED -5011

/**
 * The return value ERROR_RESTORE_FAILED indicates that
 * the restore process in the context of a restoring from a backup in form of exported data failed
 */
#define ERROR_RESTORE_FAILED -5012

/**
 * The return value ERROR_STORING_INIT_DATA_FAILED indicates that
 * the storing of the initialization data during the commissioning of the SE API
 * by the application operator failed
 */
#define ERROR_STORING_INIT_DATA_FAILED -5013

/**
 * The return value ERROR_EXPORT_CERT_FAILED indicates
 * the collection of the certificates for the export failed
 */
#define ERROR_EXPORT_CERT_FAILED -5014

/**
 * The return value ERROR_NO_LOG_MESSAGE indicates that
 * no log message parts have been found in the Secure Element
 */
#define ERROR_NO_LOG_MESSAGE -5015

/**
 * The return value ERROR_READING_LOG_MESSAGE indicates that
 * the retrieving of the log message parts that have been
 * created from Secure Element most recently failed
 */
#define ERROR_READING_LOG_MESSAGE -5016

/**
 * The return value ERROR_NO_TRANSACTION indicates that
 * no transaction is known to be open under the provided transaction number
 */
#define ERROR_NO_TRANSACTION -5017

/**
 * The return value ERROR_SE_API_NOT_INITIALIZED indicates that
 * the SE API has not been initialized
 */
#define ERROR_SE_API_NOT_INITIALIZED -5018

/**
 * The return value ERROR_TIME_NOT_SET indicates that
 * the managed data/time in the Secure Element has not been updated after the initialization of the SE API
 * or a period of absence of current for the Secure Element
 */
#define ERROR_TIME_NOT_SET -5019

/** The return value ERROR_CERTIFICATE_EXPIRED indicates that a SE API function is invoked and
 *  the certificate with the public key for the verification of the appropriate type of log messages is expired.
 *  Even if a certificate expired, the log message parts are created by the Secure Element and stored by the SE API.
 *  In this case, the return value ERROR_CERTIFICATE_EXPIRED is returned only after the data of the log message
 *  has been stored.
 */
#define ERROR_CERTIFICATE_EXPIRED -5020

/**
 * The return value ERROR_SECURE_ELEMENT_DISABLED indicates that SE API functions are invoked although the
 * Secure Element has been disabled
 */
#define ERROR_SECURE_ELEMENT_DISABLED -5021

/**
 * The return value ERROR_USER_NOT_AUTHORIZED indicates that the user who has invoked a restricted
 * SE API function is not authorized to execute this function
 */
#define ERROR_USER_NOT_AUTHORIZED -5022

/**
 * The return value ERROR_USER_NOT_AUTHENTICATED indicates that the user who has invoked a restricted
 * SE API function has not the status "authenticated"
 */
#define ERROR_USER_NOT_AUTHENTICATED -5023

/**
 * The return value ERROR_DESCRIPTION_NOT_SET_BY_MANUFACTURER indicates that the function initialize
 * has been invoked without a value for the input parameter description although the description of
 * the SE API has not been set by the manufacturer
 */
#define ERROR_DESCRIPTION_NOT_SET_BY_MANUFACTURER -5024

/**
 * The return value ERROR_DESCRIPTION_SET_BY_MANUFACTURER indicates that the function initialize has
 * been invoked with a value for the input parameter description although the description of the SE API
 * has been set by the manufacturer.
 */
#define ERROR_DESCRIPTION_SET_BY_MANUFACTURER -5025

/**
 * The return value ERROR_EXPORT_SERIAL_NUMBERS_FAILED indicates that the collection of the serial number(s) failed
 */
#define ERROR_EXPORT_SERIAL_NUMBERS_FAILED -5026

/**
 * The return value ERROR_GET_MAX_NUMBER_OF_CLIENTS_FAILED indicates that the determination of the
 * maximum number of clients that could use the SE API simultaneously failed
 */
#define ERROR_GET_MAX_NUMBER_OF_CLIENTS_FAILED -5027

/**
 * The return value ERROR_GET_CURRENT_NUMBER_OF_CLIENTS_FAILED indicates that the determination of the
 * current number of clients using the SE API failed
 */
#define ERROR_GET_CURRENT_NUMBER_OF_CLIENTS_FAILED -5028

/**
 * The return value ERROR_GET_MAX_NUMBER_TRANSACTIONS_FAILED indicates that the determination of the
 * maximum number of transactions that can be managed simultaneously failed
 */
#define ERROR_GET_MAX_NUMBER_TRANSACTIONS_FAILED -5039

/**
 * The return value ERROR_GET_CURRENT_NUMBER_OF_TRANSACTIONS_FAILED indicates
 * that the determination of the number of currently opened transactions failed
 */
#define ERROR_GET_CURRENT_NUMBER_OF_TRANSACTIONS_FAILED -5030

/**
 * The return value ERROR_GET_SUPPORTED_UPDATE_VARIANTS_FAILED is raised if the identification of the
 * supported variant(s) for updating transactions failed.
 */
#define ERROR_GET_SUPPORTED_UPDATE_VARIANTS_FAILED -5031

/**
 * The return value ERROR_DELETE_STORED_DATA_FAILED indicates that the deletion of the data from the
 * storage failed
 */
#define ERROR_DELETE_STORED_DATA_FAILED -5032

/**
 * The return value ERROR_UNEXPORTED_STORED_DATA indicates that the deletion of data from the
 * storage failed because the storage contains data that has not been exported
 */
#define ERROR_UNEXPORTED_STORED_DATA -5033

/**
 * The return value ERROR_SIGNING_SYSTEM_OPERATION_DATA_FAILED indicates that
 * the determination of the log message parts for the system operation data by the Secure Element failed
 */
#define ERROR_SIGNING_SYSTEM_OPERATION_DATA_FAILED -5034

/**
 * The return value ERROR_USER_ID_NOT_MANAGED indicates that the passed userId is not managed by the SE API
 */
#define ERROR_USER_ID_NOT_MANAGED -5035

/**
 * The return value ERROR_USER_ID_NOT_AUTHENTICATED indicates that the passed userId has not the status authenticated
 */
#define ERROR_USER_ID_NOT_AUTHENTICATED -5036

/**
 * The return value ERROR_DISABLE_SECURE_ELEMENT_FAILED indicates that the deactivation of the Secure Element failed
 */
#define ERROR_DISABLE_SECURE_ELEMENT_FAILED -5037

/**
 * The return value ERROR_INVALID_TIME indicates that
 * transmitted parameters are not valid.
 * e.g. year out of bounds
 */
#define ERROR_INVALID_TIME -5038

/**
 * The return value ERROR_GET_TIME_SYNC_VARIANT_FAILED is raised if the identification of the
 * supported variant for updating the current date/time failed.
 */
#define ERROR_GET_TIME_SYNC_VARIANT_FAILED -5039
