diff --git a/CodeJam/Main.cpp b/examples/2019/Qualification/A/Main.cpp
index 16602b7..be898a3 100644
--- a/CodeJam/Main.cpp
+++ b/examples/2019/Qualification/A/Main.cpp
@@ -4,7 +4,7 @@
 // #define IA_MODE        //remove comment on this line, to activate interactive problem mode
 #define IA_ERROR_CODE "ERROR"
 // #define XY_NOTATION    //remove commment on this line, to activate xy notation on complex numbers
-#define COMM_TYPE ll
+#define COMM_TYPE v(str)
 
 // The maintained and empty code template can be found at:
 // https://github.com/DavidS3141/CodeJamTemplate
@@ -1013,11 +1013,26 @@ namespace task {
 void init(){
 }
 
+str N;
+
 void readInput(){
+    cin >> N;
+    result.cl;
 }
 
-// write to COMM_TYPE result
+// write to OUT_TYPE result
 void calcFunction() {
+    str a = N;
+    forn(i, a.sz){
+        if(a[i]=='4'){
+            a[i] = '1';
+            N[i] = '3';
+        } else
+            a[i] = '0';
+    }
+    a = a.substr(a.find('1'));
+    result.pb(a);
+    result.pb(N);
 }
 
 } // namespace task
