1. Neue Exception definiert (ErrorInvalidTime.java) und in "exceptions" ergänzt.
2. Neue Funktion definiert (GetTimeSyncVariant) und in SEAPI.java integriert.
3. Neue Exception definiert (ErrorGetTimeSyncVariantFailed.java) und in "exceptions" ergänzt.
4. Neuer enum definiert (SyncVariants) und in SEAPI.java integriert.
5. Neuer Holdertype definiert (SyncVariantsHolder.java) und in "holdertypes" ergänzt.
6. Exception ErrorInvalidTime zur Funktion updateTime hinzugefügt.
7. Exception ErrorNoTransaction zur Funktion finishTransaction hinzugefügt.
8. Import von SyncVariantsHolder in SEAPI.java integriert.
