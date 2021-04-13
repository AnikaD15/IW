void SymTable_map(SymTable_T oSymTable, 
                  void (*pfApply)(const char *pcKey, void *pvValue, 
                                  void *pvExtra), const void *pvExtra) {
   struct SymNode *psCurrentNode;
   size_t i;
 
   assert(oSymTable != NULL);
   assert(pfApply != NULL);
 
   for (i = 0; i < oSymTable->numBuckets; i++) {
      if (oSymTable->psArray[i] == NULL) 
         continue;
 
      psCurrentNode = oSymTable->psArray[i];
 
      while (psCurrentNode != NULL) {
         (*pfApply)((void*)psCurrentNode->pcKey,
                    (void*)psCurrentNode->pvValue, (void*)pvExtra);
 
         psCurrentNode = psCurrentNode->psNextNode;
      }
   }   
}