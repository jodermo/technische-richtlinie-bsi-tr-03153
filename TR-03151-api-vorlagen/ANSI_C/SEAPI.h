#include <stdbool.h>
#include <stdint.h>
#include <time.h>

#include "Exception.h"
#include "Constant.h"

/**
 * This header file defines the different functions of the Secure Element API (SE API)
 * version 1.0.1
 */

/**
 * Represents the variants that are supported by the Secure Element to update transactions.
 */
enum UpdateVariants {
signedUpdate, unsignedUpdate, signedAndUnsignedUpdate
};

/**
 * Represents the variants that are supported by the Secure Element to update the current date/time.
 */
enum SyncVariants {
noInput, utcTime, generalizedTime, unixTime
};

/**
 * Represents the result of an authentication attempt.
 * The value ok SHALL indicate that the authentication has been successful.
 * The value failed SHALL indicate that the authentication has failed.
 * The value pinIsBlocked SHALL indicate that the PIN entry for the userId was blocked before the authentication attempt.
 * The value unknownUserId SHALL indicate that the passed userId is not managed by the SE API.
 */
enum AuthenticationResult {
auth_ok, auth_failed, pinIsBlocked, unknownUserId
};

/**
 * Represents the result of the unblock process.
 * The value ok SHALL indicate that the unblocking has been successful.
 * The value failed SHALL indicate that the unblocking has failed.
 * The value unknownUserId SHALL indicate that the passed userId is not managed by the SE API.
 * The value error SHALL indicate that an error has occurred during the execution of the function unblockUser.
 */
enum UnblockResult {
unblock_ok, unblock_failed, unknownUserId, error
};

/**
 * The function initializeDescriptionNotSet starts the initialization of the SE API by the operator of the corresponding application.
 * The initialization data in form of the description of the SE API is passed by the input parameter description.
 * The description of the SE API MUST NOT have been set by the manufacturer.
 * @param[in] description
 *            short description of the SE API.
 *                The parameter SHALL only be used if the description of the SE API has not been set by the manufacturer [REQUIRED].
 * @param[in] descriptionLength
 *                length of the string representing the description of the SE API [REQUIRED]
 * @return if the execution of the function has been successful, the return value EXECUTION_OK SHALL be returned.
 *
 *         If the execution of the function has failed, the appropriate error code SHALL be returned:
 *
 *             ERROR_SIGNING_SYSTEM_OPERATION_DATA_FAILED
 *                determination of the log message parts for the system operation data by the Secure Element failed
 *             ERROR_STORING_INIT_DATA_FAILED
 *                storing of the data for the description of the SE API failed
 *             ERROR_RETRIEVE_LOG_MESSAGE_FAILED
 *                execution of the Secure Element functionality to retrieve log message parts has failed
 *             ERROR_STORAGE_FAILURE
 *                storing of the log message has failed
 *             ERROR_CERTIFICATE_EXPIRED
 *                the certificate with the public key for the verification of the appropriate type of log messages is expired.
 *                Even if a certificate expired, the log message parts are created by the Secure Element and stored by the SE API.
 *             ERROR_SECURE_ELEMENT_DISABLED
 *                the Secure Element has been disabled
 *             ERROR_USER_NOT_AUTHORIZED
 *                the user who has invoked the function initializeDescriptionNotSet is not authorized to execute this function
 *             ERROR_USER_NOT_AUTHENTICATED
 *                the user who has invoked the function initializeDescriptionNotSet has not the status authenticated
 *             ERROR_DESCRIPTION_SET_BY_MANUFACTURER
 *                the function initializeDescriptionNotSet has been invoked with a value for the input parameter description
 *                although the description of the SE API has been set by the manufacturer
 */

short int initializeDescriptionNotSet(unsigned char *description,
                                      unsigned long int descriptionLength);

/**
 * The function initializeDescriptionSet starts the initialization of the SE API by the operator of the corresponding application.
 * The description of the SE API SHALL have been set by the manufacturer.
 * @return if the execution of the function has been successful, the return value EXECUTION_OK SHALL be returned.
 *
 *         If the execution of the function has failed, the appropriate error code SHALL be returned:
 *
 *             ERROR_SIGNING_SYSTEM_OPERATION_DATA_FAILED
 *                determination of the log message parts for the system operation data by the Secure Element failed
 *             ERROR_RETRIEVE_LOG_MESSAGE_FAILED
 *                execution of the Secure Element functionality to retrieve log message parts has failed
 *             ERROR_STORAGE_FAILURE
 *                storing of the log message has failed
 *             ERROR_CERTIFICATE_EXPIRED
 *                the certificate with the public key for the verification of the appropriate type of log messages is expired.
 *                Even if a certificate expired, the log message parts are created by the Secure Element and stored by the SE API.
 *             ERROR_SECURE_ELEMENT_DISABLED
 *                the Secure Element has been disabled
 *             ERROR_USER_NOT_AUTHORIZED
 *                the user who has invoked the function initializeDescriptionSet is not authorized to execute this function
 *             ERROR_USER_NOT_AUTHENTICATED
 *                the user who has invoked the function initializeDescriptionSet has not the status authenticated
 *             ERROR_DESCRIPTION_NOT_SET_BY_MANUFACTURER
 *                the function initializeDescriptionSet has been invoked without a value for the input parameter
 *                description although the description of the SE API has not been set by the manufacturer
 */

short int initializeDescriptionSet();

/**
 * The function updateTime updates the current date/time that is maintained by the Secure Element by passing a new date/time value
 * @param[in] newDateTime
 *                new value for the date/time maintained by the Secure Element [REQUIRED]
 * @return if the execution of the function has been successful, the return value EXECUTION_OK SHALL be returned.
 *
 *         If the execution of the function has failed, the appropriate error code SHALL be returned:
 *
 *             ERROR_UPDATE_TIME_FAILED
 *                execution of the Secure Element functionality to set the time has failed
 *             ERROR_RETRIEVE_LOG_MESSAGE_FAILED
 *                execution of the Secure Element functionality to retrieve log message parts has failed
 *             ERROR_STORAGE_FAILURE
 *                storing of the log message has failed
 *             ERROR_SE_API_NOT_INITIALIZED
 *                the SE API has not been initialized
 *             ERROR_CERTIFICATE_EXPIRED
 *                the certificate with the public key for the verification of the appropriate type of log messages is expired.
 *                Even if a certificate expired, the log message parts are created by the Secure Element and stored by the SE API.
 *             ERROR_SECURE_ELEMENT_DISABLED
 *                the Secure Element has been disabled
 *             ERROR_USER_NOT_AUTHORIZED
 *                the user who has invoked the function updateTime is not authorized to execute this function
 *             ERROR_USER_NOT_AUTHENTICATED
 *                the user who has invoked the function updateTime has not the status authenticated
 *             ERROR_INVALID_TIME
 *                the transmitted parameters are not valid
 */

short int updateTime(struct tm *newDateTime);

/**
 * The function updateTimeWithTimeSync updates the current date/time that is maintained by the Secure Element by
 * using the functionality for time synchronization of the Secure Element
 * @return if the execution of the function has been successful, the return value EXECUTION_OK SHALL be returned.
 *
 *         If the execution of the function has failed, the appropriate error code SHALL be returned:
 *
 *             ERROR_UPDATE_TIME_FAILED
 *                execution of the Secure Element functionality to update the time has failed
 *             ERROR_RETRIEVE_LOG_MESSAGE_FAILED
 *                execution of the Secure Element functionality to retrieve log message parts has failed
 *             ERROR_STORAGE_FAILURE
 *                storing of the log message has failed
 *             ERROR_SE_API_NOT_INITIALIZED
 *                the SE API has not been initialized
 *             ERROR_CERTIFICATE_EXPIRED
 *                the certificate with the public key for the verification of the appropriate type of log messages is expired.
 *                Even if a certificate expired, the log message parts are created by the Secure Element and stored by the SE API.
 *             ERROR_SECURE_ELEMENT_DISABLED
 *                the Secure Element has been disabled
 *             ERROR_USER_NOT_AUTHORIZED
 *                the user who has invoked the function updateTimeWithTimeSync is not authorized to execute this function
 *             ERROR_USER_NOT_AUTHENTICATED
 *                the user who has invoked the function updateTimeWithTimeSync has not the status authenticated
 *
 */

short int updateTimeWithTimeSync();

/**
 * The function disableSecureElement disables the Secure Element in a way that none of its functionality can be used anymore
 * @return if the execution of the function has been successful, the return value EXECUTION_OK SHALL be returned.
 *
 *         If the execution of the function has failed, the appropriate error code SHALL be returned:
 *
 *             ERROR_DISABLE_SECURE_ELEMENT_FAILED
 *                the deactivation of the Secure Element failed
 *             ERROR_TIME_NOT_SET
 *                the managed data/time in the Secure Element has not been updated after the initialization of the SE API
 *                or a period of absence of current for the Secure Element
 *             ERROR_RETRIEVE_LOG_MESSAGE_FAILED
 *                execution of the Secure Element functionality to retrieve log message parts has failed
 *             ERROR_STORAGE_FAILURE
 *                storing of the data of the log message has failed
 *             ERROR_CERTIFICATE_EXPIRED
 *                the certificate with the public key for the verification of the appropriate type of log messages is expired.
 *                Even if a certificate expired, the log message parts are created by the Secure Element and stored by the SE API.
 *             ERROR_SECURE_ELEMENT_DISABLED
 *                the Secure Element has been disabled
 *             ERROR_USER_NOT_AUTHORIZED
 *                the user who has invoked the function disableSecureElement is not authorized to execute this function
 *             ERROR_USER_NOT_AUTHENTICATED
 *                the user who has invoked the function disableSecureElement has not the status authenticated
 */

short int disableSecureElement();

/**
 * Starts a new transaction
 * @param[in] clientId
 *                represents the ID of the application that has invoked the function [REQUIRED]
 * @param[in] clientIdLength
 *                length of the array that represents the clientId  [REQUIRED]
 * @param[in] processData
 *                represents all the necessary information regarding the initial state of the process [REQUIRED]
 * @param[in] processDataLength
 *                length of the array that represents the processData [REQUIRED]
 * @param[in] processType
 *                identifies the type of the transaction as defined by the application.
 *                This string MUST NOT contain more than 100 characters [OPTIONAL]
 * @param[in] processTypeLength
 *                length of the string that represents the processType.
 *                If a null pointer is passed for the parameter processType, the value for the length SHALL be 0 [REQUIRED]
 * @param[in] additionalData
 *                reserved for future use [OPTIONAL]
 * @param[in] additionalDataLength
 *                length of the array that represents the additionalData.
 *                If a null pointer is passed for the parameter additionalData, the value for the length SHALL be 0 [REQUIRED]
 * @param[out] transactionNumber
 *                represents a transaction number that has been assigned by the Secure Element to the process [REQUIRED]
 * @param[out] logTime
 *                represents the point in time of the Secure Element when the log message was created [REQUIRED]
 * @param[out] serialNumber
 *                represents hash value over the public key of the key pair that is used for the creation of signature values
 *                in transaction log messages [REQUIRED]
 * @param[out] serialNumberLength
 *                length of the array that represents the serialNumber [REQUIRED]
 * @param[out] signatureCounter
 *                represents the current value of the signature counter [REQUIRED]
 * @param[out] signatureValue
 *                represents the signature value [OPTIONAL]
 * @param[out] signatureValueLength
 *                length of the array that represents the signature value
 *                if a value for the output parameter signatureValue is returned [OPTIONAL]
 * @return if the execution of the function has been successful, the return value EXECUTION_OK SHALL be returned.
 *
 *         If the execution of the function has failed, the appropriate error code SHALL be returned:
 *
 *             ERROR_START_TRANSACTION_FAILED
 *                the execution of the Secure Element functionality to start a transaction failed
 *             ERROR_RETRIEVE_LOG_MESSAGE_FAILED
 *                the execution of the Secure Element functionality to retrieve log message parts has failed
 *             ERROR_STORAGE_FAILURE
 *                storing of the log message failed
 *             ERROR_SE_API_NOT_INITIALIZED
 *                the SE API has not been initialized
 *             ERROR_TIME_NOT_SET
 *                the managed data/time in the Secure Element has not been updated after the initialization of the SE API
 *                or a period of absence of current for the Secure Element
 *             ERROR_CERTIFICATE_EXPIRED
 *                the certificate with the public key for the verification of the appropriate type of log messages is expired.
 *                Even if a certificate expired, the log message parts are created by the Secure Element and stored by the SE API.
 *             ERROR_SECURE_ELEMENT_DISABLED
 *                the Secure Element has been disabled
 */

short int startTransaction(unsigned char *clientId,
                               unsigned long int clientIdLength,
                               unsigned char *processData,
                               unsigned long int processDataLength,
                               unsigned char *processType,
                               unsigned long int processTypeLength,
                               unsigned char *additionalData,
                               unsigned long int additionalDataLength,
                               unsigned long int *transactionNumber,
                               struct tm *logTime,
                               unsigned char **serialNumber,
                               unsigned long int *serialNumberLength,
                               unsigned long int *signatureCounter,
                               unsigned char **signatureValue,
                               unsigned long int *signatureValueLength);

/**
 * Updates an open transaction
 * @param[in] clientId
 *                represents the ID of the application that has invoked the function [REQUIRED]
 * @param[in] clientIdLength
 *                length of the array that represents the clientId  [REQUIRED]
 * @param[in] transactionNumber
 *                parameter is used to unambiguously identify the current transaction [REQUIRED]
 * @param[in] processData
 *                represents all the new information regarding the state of the process since the start
 *                of the corresponding transaction or its last update [REQUIRED]
 * @param[in] processDataLength
 *                length of the array that represents the processData [REQUIRED]
 * @param[in] processType
 *                identifies the type of the transaction as defined by the application.
 *                This string MUST NOT contain more than 100 characters [OPTIONAL]
 * @param[in] processTypeLength
 *                length of the string that represents the processType.
 *                If a null pointer is passed for the parameter processType, the value for the length SHALL be 0 [REQUIRED]
 * @param[out] logTime
 *                represents the point in time of the Secure Element when the log message was created [CONDITIONAL]
 * @param[out] signatureValue
 *                represents the signature value [CONDITIONAL]
 * @param[out] signatureValueLength
 *                length of the array that represents the signature value if a value for the
 *                output parameter signatureValue is returned [CONDITIONAL]
 * @param[out] signatureCounter
 *                represents the current value of the signature counter [CONDITIONAL]
 * @return if the execution of the function has been successful, the return value EXECUTION_OK SHALL be returned.
 *
 *         If the execution of the function has failed, the appropriate error code SHALL be returned:
 *
 *             ERROR_UPDATE_TRANSACTION_FAILED
 *                the execution of the Secure Element functionality to update a transaction failed
 *             ERROR_RETRIEVE_LOG_MESSAGE_FAILED
 *                the execution of the Secure Element functionality to retrieve log message parts has failed
 *             ERROR_STORAGE_FAILURE
 *                storing of the log message failed
 *             ERROR_NO_TRANSACTION
 *                no transaction is known to be open under the provided transaction number
 *             ERROR_SE_API_NOT_INITIALIZED
 *                the SE API has not been initialized
 *             ERROR_TIME_NOT_SET
 *                the managed data/time in the Secure Element has not been updated after the initialization of the SE API
 *                or a period of absence of current for the Secure Element
 *             ERROR_CERTIFICATE_EXPIRED
 *                the certificate with the public key for the verification of the appropriate type of log messages is expired.
 *                Even if a certificate expired, the log message parts are created by the Secure Element and stored by the SE API.
 *             ERROR_SECURE_ELEMENT_DISABLED
 *                the Secure Element has been disabled
 *
 */

short int updateTransaction(unsigned char *clientId,
                                unsigned long int clientIdLength,
                                unsigned long int transactionNumber,
                                unsigned char *processData,
                                unsigned long int processDataLength,
                                unsigned char *processType,
                                unsigned long int processTypeLength,
                                struct tm *logTime,
                                unsigned char **signatureValue,
                                unsigned long int *signatureValueLength,
                                unsigned long int *signatureCounter);

/**
 * Finishes an open transaction
 * @param[in] clientId
 *                 represents the ID of the application that has invoked the function [REQUIRED]
 * @param[in] clientIdLength
 *                 length of the array that represents the clientId  [REQUIRED]
 * @param[in] transactionNumber
 *                 parameter is used to unambiguously identify the current transaction [REQUIRED]
 * @param[in] processData
 *                 represents all the information regarding the final state of the process [REQUIRED]
 * @param[in] processDataLength
 *                 length of the array that represents the processData [REQUIRED]
 * @param[in] processType
 *                 identifies the type of the transaction as defined by the application
 *                 This string MUST NOT contain more than 100 characters [OPTIONAL]
 * @param[in] processTypeLength
 *                 length of the string that represents the processType.
 *                 If a null pointer is passed for the parameter processType, the value for the length SHALL be 0 [REQUIRED]
 * @param[in] additionalData   reserved for future use [OPTIONAL]
 * @param[in] additionalDataLength
 *                 length of the array that represents the additionalData.
 *                 If a null pointer is passed for the parameter additionalData, the value for the length SHALL be 0 [REQUIRED]
 * @param[out] logTime
 *                 represents the point in time of the Secure Element when the log message was created [REQUIRED]
 * @param[out] signatureValue
 *                 represents the signature value [OPTIONAL]
 * @param[out] signatureValueLength
 *                 length of the array that represents the signature value if a value for the
 *                 output parameter signatureValue is returned [OPTIONAL]
 * @param[out] signatureCounter
 *                 represents the current value of the signature counter [REQUIRED]
 * @return if the execution of the function has been successful, the return value EXECUTION_OK SHALL be returned.
 *
 *         If the execution of the function has failed, the appropriate error code SHALL be returned:
 *
 *             ERROR_FINISH_TRANSACTION_FAILED
 *                the execution of the Secure Element functionality to finish a transaction failed
 *             ERROR_RETRIEVE_LOG_MESSAGE_FAILED
 *                the execution of the Secure Element functionality to retrieve log message parts has failed
 *             ERROR_STORAGE_FAILURE
 *                storing of the log message failed
 *             ERROR_NO_TRANSACTION
 *                no transaction is known to be open under the provided transaction number
 *             ERROR_SE_API_NOT_INITIALIZED
 *                the SE API has not been initialized
 *             ERROR_TIME_NOT_SET
 *                the managed data/time in the Secure Element has not been updated after the initialization
 *                of the SE API or a period of absence of current for the Secure Element
 *             ERROR_CERTIFICATE_EXPIRED
 *                the certificate with the public key for the verification of the appropriate type of log messages is expired.
 *                Even if a certificate expired, the log message parts are created by the Secure Element and stored by the SE API.
 *             ERROR_SECURE_ELEMENT_DISABLED   the Secure Element has been disabled
 */

short int finishTransaction(unsigned char *clientId,
                                unsigned long int clientIdLength,
                                unsigned long int transactionNumber,
                                unsigned char *processData,
                                unsigned long int processDataLength,
                                unsigned char *processType,
                                unsigned long int processTypeLength,
                                unsigned char *additionalData,
                                unsigned long int additionalDataLength,
                                struct tm *logTime,
                                unsigned char **signatureValue,
                                unsigned long int *signatureValueLength,
                                unsigned long int *signatureCounter);

/**
 * Exports the transaction log messages, containing the process and protocol data, that correspond to a certain transaction
 * and clientId. Additionally, the function SHALL export all system log messages and audit log messages whose signature
 * counters are contained in the following interval:
 * 	   Signature counter of the transaction log message for the start of the transaction and the signature
 * 	   counter of the transaction log message for the end of the transaction (inclusive).
 * Furthermore, additional files that are needed to verify the signatures included in the log messages are exported
 * @param[in] transactionNumber
 *                indicates the transaction whose corresponding log messages are relevant for the export [REQUIRED]
 * @param[in] clientId
 *                ID of a client application that has used the API to log transactions.
 *                Only transaction log messages that correspond to the clientId are relevant for the export. [REQUIRED]
 * @param[in] clientIdLength
 *                length of the array that represents the clientId  [REQUIRED]
 * @param[out] exportedData
 *                selected log messages and additional files needed to verify the signatures included
 *                in the log messages [REQUIRED]
 * @param[out] exportedDataLength
 *                length of the array that represents the exportedData [REQUIRED]
 * @return if the execution of the function has been successful, the return value EXECUTION_OK SHALL be returned.
 *
 *         If the execution of the function has failed, the appropriate error code SHALL be returned:
 *
 *             ERROR_TRANSACTION_NUMBER_NOT_FOUND
 *                no data has been found for the provided transactionNumber
 *             ERROR_ID_NOT_FOUND
 *                no data has been found for the provided clientId
 *             ERROR_SE_API_NOT_INITIALIZED
 *                the SE API has not been initialized
 */

short int exportDataFilteredByTransactionNumberAndClientId(unsigned long int transactionNumber,
                                                               unsigned char *clientId,
                                                               unsigned long int clientIdLength,
                                                               unsigned char **exportedData,
                                                               unsigned long int *exportedDataLength);

/**
 * Exports the transaction log messages, containing the process and protocol data, that correspond to a certain transaction.
 * Additionally, the function SHALL export all system log messages and audit log messages whose signature
 * counters are contained in the following interval:
 * 	   Signature counter of the transaction log message for the start of the transaction and the signature
 * 	   counter of the transaction log message for the end of the transaction (inclusive)
 * Furthermore, additional files that are needed to verify the signatures, included in the log messages, are exported
 * @param[in] transactionNumber
 *                indicates the transaction whose corresponding log messages are relevant for the export [REQUIRED]
 * @param[out] exportedData
 *                selected log messages and additional files needed to verify the signatures included in the log messages [REQUIRED]
 * @param[out] exportedDataLength
 *                length of the array that represents the exportedData [REQUIRED]
 * @return if the execution of the function has been successful, the return value EXECUTION_OK SHALL be returned.
 *
 *         If the execution of the function has failed, the appropriate error code SHALL be returned:
 *
 *             ERROR_TRANSACTION_NUMBER_NOT_FOUND
 *                no data has been found for the provided transactionNumber
 *             ERROR_SE_API_NOT_INITIALIZED
 *                the SE API has not been initialized
 */
short int exportDataFilteredByTransactionNumber(unsigned long int transactionNumber,
                                                    unsigned char **exportedData,
                                                    unsigned long int *exportedDataLength);

/**
 * Exports the transaction log messages, containing the process and protocol data, that are relevant for a
 * certain interval of transactions. Additionally, the function SHALL export all system log messages and audit log
 * messages whose signature counters are contained in this interval.
 * Furthermore, additional files that are needed to verify the signatures, included in the log messages, are exported.
 * @param[in] startTransactionNumber
 *                defines the transaction number (inclusive) regarding the start of the interval of relevant log messages [REQUIRED]
 * @param[in] endTransactionNumber
 *                defines the transaction number (inclusive) regarding the end of the interval of relevant log messages [REQUIRED]
 * @param[in] maximumNumberRecords
 *                if the value of this parameter is not 0, the function SHALL only return the log messages if the number
 *                of relevant records is less or equal to the number of maximum records.
 *                If the value of the parameter is 0, the function SHALL return all selected log messages [REQUIRED]
 * @param[out] exportedData
 *                selected log messages and additional files needed to verify the signatures included in the log messages [REQUIRED]
 * @param[out] exportedDataLength
 *                length of the array that represents the exportedData [REQUIRED]
 * @return if the execution of the function has been successful, the return value EXECUTION_OK SHALL be returned.
 *
 *         If the execution of the function has failed, the appropriate error code SHALL be returned:
 *
 *             ERROR_PARAMETER_MISMATCH
 *                mismatch in parameters of the function
 *             ERROR_TRANSACTION_NUMBER_NOT_FOUND
 *                no data has been found for the provided transaction numbers
 *             ERROR_TOO_MANY_RECORDS
 *                the amount of requested records exceeds the parameter maximumNumberRecords
 *             ERROR_SE_API_NOT_INITIALIZED
 *                the SE API has not been initialized
 */

short int exportDataFilteredByTransactionNumberInterval(unsigned long int startTransactionNumber,
                                                            unsigned long int endTransactionNumber,
                                                            long int maximumNumberRecords,
                                                            unsigned char **exportedData,
                                                            unsigned long int *exportedDataLength);

/**
 * Exports the transaction log messages, containing the process and protocol data, that are relevant for a certain
 * interval of transactions. The transaction log messages in this interval SHALL correspond to the passed clientId.
 * Additionally, the function SHALL export all system log messages and audit log messages whose signature counters
 * are contained in the interval.
 * Furthermore, additional files that are needed to verify the signatures, included in the log messages, are exported.
 * @param[in] startTransactionNumber
 *                defines the transaction number (inclusive) regarding the start of the interval of relevant log messages [REQUIRED]
 * @param[in] endTransactionNumber
 *                defines the transaction number (inclusive) regarding the end of the interval of relevant log messages [REQUIRED]
 * @param[in] clientId
 *                ID of a client application that has used the API to log transactions.
 *                Only transaction log messages that corresponds to the clientId are relevant for the export [REQUIRED]
 * @param[in] clientIdLength
 *                length of the array that represents the clientId  [REQUIRED]
 * @param[in] maximumNumberRecords
 *                if the value of this parameter is not 0, the function SHALL only return the log messages if the number
 *                of relevant records is less or equal to the number of maximum records.
 *                If the value of the parameter is 0, the function SHALL return all selected log messages [REQUIRED]
 * @param[out] exportedData
 *                selected log messages and additional files needed to verify the signatures included in the log messages [REQUIRED]
 * @param[out] exportedDataLength
 *                length of the array that represents the exportedData [REQUIRED]
 * @return if the execution of the function has been successful, the return value EXECUTION_OK SHALL be returned.
 *
 *  	   If the execution of the function has failed, the appropriate error code SHALL be returned:
 *
 *             ERROR_PARAMETER_MISMATCH
 *                mismatch in parameters of the function
 *             ERROR_TRANSACTION_NUMBER_NOT_FOUND
 *                no data has been found for the provided transaction numbers
 *             ERROR_ID_NOT_FOUND
 *                no data has been found for the provided clientId
 *             ERROR_TOO_MANY_RECORDS
 *                the amount of requested records exceeds the parameter maximumNumberRecords
 *             ERROR_SE_API_NOT_INITIALIZED
 *                the SE API has not been initialized
 *
 */

short int exportDataFilteredByTransactionNumberIntervalAndClientId(unsigned long int startTransactionNumber,
                                                                       unsigned long int endTransactionNumber,
                                                                       unsigned char *clientId,
                                                                       unsigned long int clientIdLength,
                                                                       long int maximumNumberRecords,
                                                                       unsigned char **exportedData,
                                                                       unsigned long int *exportedDataLength);

/**
 * Exports the transaction log messages, system log messages and audit log messages
 * that have been created in a certain period of time.
 * Furthermore, additional files that are needed to verify the signatures included in the log messages are exported.
 * @param[in] startDate
 *                defines the starting time (inclusive) for the period in that the relevant log messages have been created.
 *                The value for the parameter SHALL be encoded in a format that conforms to BSI TR-03151.
 *                If a value for the input parameter endDate is passed, startDate SHALL be [OPTIONAL].
 *                If no value for the input parameter endDate is passed, startDate SHALL be [REQUIRED].
 * @param[in] endDate
 *                defines the end time (inclusive) for the period in that relevant log messages have been created.
 *                The value for the parameter SHALL be encoded in a format that conforms to BSI TR-03151.
 *                If a value for the input parameter startDate is passed, endDate SHALL be [OPTIONAL].
 *                If no value for the input parameter startDate is passed, endDate SHALL be [REQUIRED].
 * @param[in] maximumNumberRecords
 *                if the value of this parameter is not 0, the function SHALL only return the log messages if the number
 *                of relevant records is less or equal to the number of maximum records.
 *                If the value of the parameter is 0, the function SHALL return all selected log messages [REQUIRED]
 * @param[out] exportedData
 *                selected log messages and additional files needed to verify the signatures included in the log messages [REQUIRED]
 * @param[out] exportedDataLength
 *                length of the array that represents the exportedData [REQUIRED]
 * @return if the execution of the function has been successful, the return value EXECUTION_OK SHALL be returned.
 *
 *         If the execution of the function has failed, the appropriate error code SHALL be returned:
 *
 *             ERROR_PARAMETER_MISMATCH
 *                mismatch in parameters of the function
 *             ERROR_NO_DATA_AVAILABLE
 *                no data has been found for the provided selection
 *             ERROR_TOO_MANY_RECORDS
 *                the amount of requested records exceeds the parameter maximumNumberRecords
 *             ERROR_SE_API_NOT_INITIALIZED
 *                the SE API has not been initialized
 */

short int exportDataFilteredByPeriodOfTime(struct tm *startDate,
                                               struct tm *endDate,
                                               long int maximumNumberRecords,
                                               unsigned char **exportedData,
                                               unsigned long int *exportedDataLength);

/**
 * Exports the transaction log messages, system log messages and audit log messages that have been created in a certain period of time.
 * The transaction log messages in this period of time SHALL correspond to the passed clientId.
 * Furthermore, additional files that are needed to verify the signatures included in the log messages are exported
 * @param[in] startDate
 *                defines the starting time (inclusive) for the period in that the relevant log messages have been created.
 *                The value for the parameter SHALL be encoded in a format that conforms to BSI TR-03151.
 *                If a value for the input parameter endDate is passed, startDate SHALL be [OPTIONAL].
 *                If no value for the input parameter endDate is passed, startDate SHALL be [REQUIRED].
 * @param[in] endDate
 *                defines the end time (inclusive) for the period in that relevant log messages have been created.
 *                The value for the parameter SHALL be encoded in a format that conforms to BSI TR-03151.
 *                If a value for the input parameter startDate is passed, endDate SHALL be [OPTIONAL].
 *                If no value for the input parameter startDate is passed, endDate SHALL be [REQUIRED].
 * @param[in] clientId
 *                ID of a client application that has used the API to log transactions.
                      Only transaction log messages that corresponds to the clientId are relevant for the export [REQUIRED]
 * @param[in] clientIdLength
 *                length of the array that represents the clientId  [REQUIRED]
 * @param[in] maximumNumberRecords
 *                if the value of this parameter is not 0, the function SHALL only return the log messages if the number
 *                of relevant records is less or equal to the number of maximum records.
 *                If the value of the parameter is 0, the function SHALL return all selected log messages [REQUIRED]
 * @param[out] exportedData
 *                selected log messages and additional files needed to verify the signatures included in the log messages [REQUIRED]
 * @param[out] exportedDataLength
 *                length of the array that represents the exportedData [REQUIRED]
 * @return if the execution of the function has been successful, the return value EXECUTION_OK SHALL be returned.
 *
 *         If the execution of the function has failed, the appropriate error code SHALL be returned:
 *
 *             ERROR_PARAMETER_MISMATCH
 *                mismatch in parameters of the function
 *             ERROR_NO_DATA_AVAILABLE
 *                no data has been found for the provided selection
 *             ERROR_ID_NOT_FOUND
 *                no data has been found for the provided clientId
 *             ERROR_TOO_MANY_RECORDS
 *                the amount of requested records exceeds the parameter maximumNumberRecords
 *             ERROR_SE_API_NOT_INITIALIZED
 *                the SE API has not been initialized
 *
 */

short int exportDataFilteredByPeriodOfTimeAndClientId(struct tm *startDate,
                                                          struct tm *endDate,
                                                          unsigned char *clientId,
                                                          unsigned long int clientIdLength,
                                                          long int maximumNumberRecords,
                                                          unsigned char **exportedData,
                                                          unsigned long int *exportedDataLength);

/**
 * Exports all stored transaction log messages, system log message and audit log messages.
 * Furthermore, additional files that are needed to verify the signatures included in the log messages are exported.
 * @param[in] maximumNumberRecords
 *                if the value of this parameter is not 0, the function SHALL only return the log messages if the number
 *                of relevant records is less or equal to the number of maximum records.
 *                If the value of the parameter is 0, the function SHALL return all stored log messages [REQUIRED]
 * @param[out] exportedData
 *                all stored log messages and additional files needed to verify the signatures included in the log messages [REQUIRED]
 * @param[out] exportedDataLength
 *                length of the array that represents the exportedData [REQUIRED]
 * @return if the execution of the function has been successful, the return value EXECUTION_OK SHALL be returned.
 *
 *         If the execution of the function has failed, the appropriate error code SHALL be returned:
 *
 *             ERROR_TOO_MANY_RECORDS
 *                the amount of requested records exceeds the parameter maximumNumberRecords
 *             ERROR_SE_API_NOT_INITIALIZED
 *                the SE API has not been initialized
 *
 */

short int exportData(long int maximumNumberRecords,
                         unsigned char **exportedData,
                         unsigned long int *exportedDataLength);

/**
 * Exports the certificates of the certificate chains. These certificates belong to
 * the public keys of the key pairs that are used for the creation of signature values in log messages
 * @param[out] certificates
 *                the TAR archive that contains all certificates that are necessary for the verification of log messages.
 *                The format of the TAR archive and the contained certificates SHALL conform to BSI TR-03151 [REQUIRED]
 * @param[out] certificatesLength
 *                length of the array that represent the certificate(s) [REQUIRED]
 * @return if the execution of the function has been successful, the return value EXECUTION_OK SHALL be returned.
 *
 *         If the execution of the function has failed, the appropriate error code SHALL be returned:
 *
 *             ERROR_EXPORT_CERT_FAILED
 *                the collection of the certificates for the export failed
 *             ERROR_SE_API_NOT_INITIALIZED
 *                the SE API has not been initialized
 */

short int exportCertificates(unsigned char **certificates,
                                 unsigned long int *certificatesLength);

/**
 * Restores a backup in the SE API and storage. The backup data includes log messages and certificates
 * that have been exported by using the exportData function.
 * Log messages and certificates are passed in the TAR archive that has been returned during the export of the log messages and certificates.
 * The function SHALL store the data of the passed log messages in the storage. If an imported log message
 * has a file name that already exists in the storage, a counter SHALL be appended to the file name of the imported log message.
 * The function SHALL store an imported certificate only if no certificate of the same name is managed by the SE API.
 * @param[in] restoreData
 *                represents the TAR archive that contains the log messages and certificates for the restore process [REQUIRED]
 * @param[in] restoreDataLength
 *                represents the length of the array that represents the restoreData [REQUIRED]
 * @return if the execution of the function has been successful, the return value EXECUTION_OK SHALL be returned.
 *
 *         If the execution of the function has failed, the appropriate error code SHALL be returned:
 *
 *             ERROR_RESTORE_FAILED
 *                the restore process has failed
 *             ERROR_SE_API_NOT_INITIALIZED
 *                the SE API has not been initialized
 *             ERROR_USER_NOT_AUTHORIZED
 *                the user who has invoked the function restoreFromBackup is not authorized to execute this function
 *             ERROR_USER_NOT_AUTHENTICATED
 *                the user who has invoked the function restoreFromBackup has not the status authenticated
 */

short int restoreFromBackup(unsigned char *restoreData,
                                unsigned long int restoreDataLength);

/**
 * Reads a log message that bases on the last log message parts that have been produced and processed by the Secure Element
 * @param[out] logMessage
 *                contains the last log message that the Secure Element has produced [REQUIRED]
 * @param[out] logMessageLength
 *                length of the array that represents the last log message [REQUIRED]
 * @return if the execution of the function has been successful, the return value EXECUTION_OK SHALL be returned.
 *
 *         If the execution of the function has failed, the appropriate error code SHALL be returned:
 *
 *             ERROR_NO_LOG_MESSAGE
 *                no log message parts are found
 *             ERROR_READING_LOG_MESSAGE
 *                error while retrieving log message parts
 *             ERROR_SE_API_NOT_INITIALIZED
 *                the SE API has not been initialized
 *             ERROR_SECURE_ELEMENT_DISABLED
 *                the Secure Element has been disabled
 */

short int readLogMessage(unsigned char **logMessage,
                             unsigned long int *logMessageLength);

/**
 * Exports the serial number(s) of the SE API. A serial number is a hash value of a public key that belongs to a key pair
 * whose private key is used to create signature values of log messages.
 * @param[out] serialNumbers
 *                the serial number(s) of the SE API.
 *                The serial number(s) SHALL be encoded in the TLV structure defined in BSI TR-03151. [REQUIRED]
 * @param[out] serialNumbersLength
 *                length of the array that represents the serial number(s) [REQUIRED]
 * @return if the execution of the function has been successful, the return value EXECUTION_OK SHALL be returned.
 *
 *         If the execution of the function has failed, the appropriate error code SHALL be returned:
 *
 *             ERROR_EXPORT_SERIAL_NUMBERS_FAILED
 *                the collection of the serial number(s) failed
 *             ERROR_SE_API_NOT_INITIALIZED
 *                the SE API has not been initialized
 */

short int exportSerialNumbers(unsigned char **serialNumbers,
                                  unsigned long int *serialNumbersLength);

/**
 * Supplies the maximal number of clients that can use the functionality to log transactions of the SE API simultaneously
 * @param[out] maxNumberClients
 *                maximum number of clients that can use the functionality to log transactions of the SE API simultaneously [REQUIRED]
 * @return if the execution of the function has been successful, the return value EXECUTION_OK SHALL be returned.
 *
 *         If the execution of the function has failed, the appropriate error code SHALL be returned:
 *
 *              ERROR_GET_MAX_NUMBER_OF_CLIENTS_FAILED
 *                 the determination of the maximum number of clients that could use the SE API simultaneously failed
 *              ERROR_SE_API_NOT_INITIALIZED
 *                 the SE API has not been initialized
 *              ERROR_SECURE_ELEMENT_DISABLED
 *                 the Secure Element has been disabled
 */

short int getMaxNumberOfClients(unsigned long int *maxNumberClients);

/**
 * Supplies the number of clients that are currently using the functionality to log transactions of the SE API.
 * @param[out] currentNumberClients
 *                the number of clients that are currently using the functionality of the SE API [REQUIRED]
 * @return if the execution of the function has been successful, the return value EXECUTION_OK SHALL be returned.
 *
 *         If the execution of the function has failed, the appropriate error code SHALL be returned:
 *
 *             ERROR_GET_CURRENT_NUMBER_OF_CLIENTS_FAILED
 *                the determination of the current number of clients using the SE API failed
 *             ERROR_SE_API_NOT_INITIALIZED
 *                the SE API has not been initialized
 *             ERROR_SECURE_ELEMENT_DISABLED
 *                the Secure Element has been disabled
 */

short int getCurrentNumberOfClients(unsigned long int *currentNumberClients);

/**
 * Supplies the maximal number of simultaneously opened transactions that can be managed by the SE API
 * @param[out] maxNumberTransactions
 *                 maximum number of simultaneously opened transactions that can be managed by the SE API [REQUIRED]
 * @return if the execution of the function has been successful, the return value EXECUTION_OK SHALL be returned.
 *
 *         If the execution of the function has failed, the appropriate error code SHALL be returned:
 *
 *             ERROR_GET_MAX_NUMBER_TRANSACTIONS_FAILED
 *                the determination of the maximum number of transactions that can be managed simultaneously failed
 *             ERROR_SE_API_NOT_INITIALIZED
 *                the SE API has not been initialized
 *             ERROR_SECURE_ELEMENT_DISABLED
 *                the Secure Element has been disabled
 */

short int getMaxNumberOfTransactions(unsigned long int *maxNumberTransactions);

/**
 * Supplies the number of open transactions that are currently managed by the SE API
 * @param[out] currentNumberTransactions
 *                the number of open transactions that are currently managed by the SE API [REQUIRED]
 * @return if the execution of the function has been successful, the return value EXECUTION_OK SHALL be returned.
 *
 *         If the execution of the function has failed, the appropriate error code SHALL be returned:
 *
 *             ERROR_GET_CURRENT_NUMBER_OF_TRANSACTIONS_FAILED
 *                the determination of the number of open transactions that are currently managed by the SE API failed
 *             ERROR_SE_API_NOT_INITIALIZED
 *                the SE API has not been initialized
 *             ERROR_SECURE_ELEMENT_DISABLED
 *                the Secure Element has been disabled
 */

short int getCurrentNumberOfTransactions(unsigned long int *currentNumberTransactions);

/**
 * Supplies the supported variants to update transactions
 * @param[out] supportedUpdateVariants
 *                the supported variant(s) to update a transaction [REQUIRED]
 * @return if the execution of the function has been successful, the return value EXECUTION_OK SHALL be returned
 *
 *         If the execution of the function has failed, the appropriate error code SHALL be returned:
 *
 *             ERROR_GET_SUPPORTED_UPDATE_VARIANTS_FAILED
 *                the identification of the supported variant(s) to update transactions failed
 *             ERROR_SE_API_NOT_INITIALIZED
 *                the SE API has not been initialized
 *             ERROR_SECURE_ELEMENT_DISABLED
 *                the Secure Element has been disabled
 */

short int getSupportedTransactionUpdateVariants(enum UpdateVariants *supportedUpdateVariants);

/**
 * Deletes all data that is stored in the storage. The function SHALL delete
 * only data that has been exported.
 * @return if the execution of the function has been successful, the return value EXECUTION_OK SHALL be returned.
 *
 *         If the execution of the function has failed, the appropriate error code SHALL be returned:
 *
 *             ERROR_DELETE_STORED_DATA_FAILED
 *                the deletion of the data from the storage failed
 *             ERROR_UNEXPORTED_STORED_DATA
 *                the deletion of data from the storage failed because the storage contains data that has not been exported
 *             ERROR_SE_API_NOT_INITIALIZED
 *                the SE API has not been initialized
 *             ERROR_USER_NOT_AUTHORIZED
 *                the user who has invoked the function deleteStoredData is not authorized to execute this function
 *             ERROR_USER_NOT_AUTHENTICATED
 *                the user who has invoked the function deleteStoredData has not the status authenticated
 */
short int deleteStoredData();

/**
 * Supplies the supported variants to update the current date/time
 * @param[out] supportedSyncVariant
 *                the supported variant to update  the current date/time [REQUIRED]
 * @return if the execution of the function has been successful, the return value EXECUTION_OK SHALL be returned
 *
 *         If the execution of the function has failed, the appropriate error code SHALL be returned:
 *
 *             ERROR_GET_TIME_SYNC_VARIANT_FAILED
 *                the identification of the supported variant to update the current date/time failed
 *             ERROR_SE_API_NOT_INITIALIZED
 *                the SE API has not been initialized
 *             ERROR_SECURE_ELEMENT_DISABLED
 *                the Secure Element has been disabled
 */

short int GetTimeSyncVariant(enum SyncVariants *supportedSyncVariant);

/**
 * Enables an authorized user or application to authenticate to the SE API for the usage of restricted SE API functions
 * @param[in] userId
 *                the ID of the user who or application that wants to be authenticated [REQUIRED]
 * @param[in] userIdLength
 *                the length of the array that represents the userId [REQUIRED]
 * @param[in] pin
 *                the PIN for the authentication [REQUIRED]
 * @param[in] pinLength
 *                the length of the array that represents the pin [REQUIRED]
 * @param[out] authenticationResult
 *                the result of the authentication [REQUIRED]
 * @param[out] remainingRetries
 *                the number of remaining retries to enter a PIN [REQUIRED]
 * @return if the execution of the function has been successful, the return value EXECUTION_OK SHALL be returned.
 *
 *         If the authentication attempt has failed, the return value AUTHENTICATION_FAILED SHALL be returned.
 *
 *         If an error occurs during the processing the appropriate error code SHALL be returned:
 *
 *             ERROR_SIGNING_SYSTEM_OPERATION_DATA_FAILED
 *                the determination of the log message parts for the system operation data by the Secure Element failed
 *             ERROR_RETRIEVE_LOG_MESSAGE_FAILED
 *                the execution of the Secure Element functionality to retrieve log message parts has failed
 *             ERROR_STORAGE_FAILURE
 *                storing of the data of the log message failed
 *             ERROR_SECURE_ELEMENT_DISABLED
 *                the Secure Element has been disabled
 *
 */
short int authenticateUser(unsigned char *userId,
                               unsigned long int userIdLength,
                               unsigned char *pin,
                               unsigned long int pinLength,
                               enum AuthenticationResult *authenticationResult,
                           short int *remainingRetries);

/**
 * Enables the log out of an authenticated user or application from the SE API
 * @param[in] userId
 *                the ID of the user who or application that wants to log out from the SE API [REQUIRED]
 * @param[in] userIdLength
 *                the length of the array that represents the userId [REQUIRED]
 * @return if the execution of the function has been successful, the return value EXECUTION_OK SHALL be returned.
 *
 *         If the execution of the function has failed, the appropriate error code SHALL be returned:
 *
 *             ERROR_USER_ID_NOT_MANAGED
 *                the passed userId is not managed by the SE API
 *             ERROR_SIGNING_SYSTEM_OPERATION_DATA_FAILED
 *                the determination of the log message parts for the system operation data by the Secure Element failed
 *             ERROR_USER_ID_NOT_AUTHENTICATED
 *                the passed userId has not the status authenticated
 *             ERROR_RETRIEVE_LOG_MESSAGE_FAILED
 *                the execution of the Secure Element functionality to retrieve log message parts has failed
 *             ERROR_STORAGE_FAILURE
 *                storing of the data of the log message failed
 *             ERROR_SECURE_ELEMENT_DISABLED
 *                the Secure Element has been disabled
 */

short int logOut(unsigned char *userId,
                 unsigned long int userIdLength);

/**
 * Enables the unblocking for the entry of a PIN and the definition of a new PIN
 * for the authentication of authorized users or applications
 * @param[in] userId
 *                the ID of the user who or application that wants to unblock the corresponding PIN entry [REQUIRED]
 * @param[in] userIdLength
 *                the length of the array that represents the userId [REQUIRED]
 * @param[in] puk
 *                the PUK of the user/application [REQUIRED]
 * @param[in] pukLength
 *                the length of the array that represents the puk [REQUIRED]
 * @param[in] newPin
 *                the new PIN for the user/application [REQUIRED]
 * @param[in] newPinLength
 *                the length of the array that represents the newPin [REQUIRED]
 * @param[out] unblockResult
 *                the result of the unblock procedure [REQUIRED]
 * @return if the execution of the function has been successful, the return value EXECUTION_OK SHALL be returned.
 *
 *         If the execution of attempt to unblock a PIN entry has failed, the return value UNBLOCK_FAILED SHALL be returned.
 *
 *         If an error occurs during the processing the appropriate error code SHALL be returned:
 *
 *             ERROR_SIGNING_SYSTEM_OPERATION_DATA_FAILED
 *                the determination of the log message parts for the system operation data by the Secure Element failed
 *             ERROR_RETRIEVE_LOG_MESSAGE_FAILED
 *                the execution of the Secure Element functionality to retrieve log message parts has failed
 *             ERROR_STORAGE_FAILURE
 *                storing of the data of the log message failed
 *             ERROR_SECURE_ELEMENT_DISABLED
 *                the Secure Element has already been disabled
 */
short int unblockUser(unsigned char *userId,
                          unsigned long int userIdLength,
                          unsigned char *puk,
                          unsigned long int pukLength,
                          unsigned char *newPin,
                          unsigned long int newPinLength,
                          enum UnblockResult *unblockResult);

