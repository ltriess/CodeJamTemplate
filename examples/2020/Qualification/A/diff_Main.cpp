diff --git a/CodeJam/Main.cpp b/examples/2020/Qualification/A/Main.cpp
index 0493fca..3966dc6 100644
--- a/CodeJam/Main.cpp
+++ b/examples/2020/Qualification/A/Main.cpp
@@ -2,7 +2,7 @@
 // #define IA_MODE        //remove comment on this line, to activate interactive problem mode
 // #define XY_NOTATION    //remove commment on this line, to activate xy notation on complex numbers
 #define ERROR_WORD "IMPOSSIBLE"
-#define COMM_TYPE ll
+#define COMM_TYPE v(ll)
 #define IA_ERROR_CODE "ERROR"
 
 // The maintained and empty code template can be found at:
@@ -828,11 +828,44 @@ namespace task {
 void init(){
 }
 
+ll k, N;
+v(v(ll)) Mij;
+v(set(ll)) rc, cc;
+
 void readInput(){
+    cin >> N;
+    Mij.clear();
+    rc.clear();
+    cc.clear();
+    rc = v(set(ll))(N);
+    cc = v(set(ll))(N);
+    ll t;
+    k = 0;
+    forn(i,N){
+        Mij.pb(v(ll)());
+        forn(j,N){
+            cin >> t;
+            Mij.bk.pb(t);
+            rc[i].insert(t-1);
+            cc[j].insert(t-1);
+            if(i==j){
+                k+=t;
+            }
+        }
+    }
 }
 
 // write to COMM_TYPE result
 void calcFunction() {
+    result.clear();
+    result.pb(k);
+    ll r=0, c=0;
+    forn(i, N){
+        r+= rc[i].sz < N;
+        c += cc[i].sz < N;
+    }
+    result.pb(r);
+    result.pb(c);
 }
 
 } // namespace task
