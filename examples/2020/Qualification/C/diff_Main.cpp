diff --git a/CodeJam/Main.cpp b/examples/2020/Qualification/C/Main.cpp
index 0493fca..60c05d4 100644
--- a/CodeJam/Main.cpp
+++ b/examples/2020/Qualification/C/Main.cpp
@@ -1,8 +1,8 @@
-// #define DEFAULT_VAL    //remove comment on this line, to activate default value trigger
+#define DEFAULT_VAL    //remove comment on this line, to activate default value trigger
 // #define IA_MODE        //remove comment on this line, to activate interactive problem mode
 // #define XY_NOTATION    //remove commment on this line, to activate xy notation on complex numbers
 #define ERROR_WORD "IMPOSSIBLE"
-#define COMM_TYPE ll
+#define COMM_TYPE str
 #define IA_ERROR_CODE "ERROR"
 
 // The maintained and empty code template can be found at:
@@ -806,7 +806,7 @@ int main() {
         std::cout << result << std::endl;
 #endif /*DEFAULT_VAL*/
 #ifdef DEFAULT_VAL
-        if(result>=0){
+        if(result.sz>0){
             std::cout << result << std::endl;
         }
         else{
@@ -828,11 +828,92 @@ namespace task {
 void init(){
 }
 
+ll N;
+v(ll) Si, Ei;
+
 void readInput(){
+    Si.clear();
+    Ei.clear();
+    cin >> N;
+    ll s,e;
+    forn(i,N){
+        cin >> s >> e;
+        Si.pb(s);
+        Ei.pb(e);
+    }
+}
+
+v(v(ll)) overlaps;
+void compute_overlaps(){
+    overlaps.clear();
+    overlaps = v(v(ll))(N);
+    forn(i, N){
+        forn(j,i){
+            if(Si[i]<Ei[j] && Ei[i]>Si[j]){
+                overlaps[i].pb(j);
+                overlaps[j].pb(i);
+            }
+        }
+    }
+}
+
+v(ll) resultv;
+
+bool recur(ll act, ll p){
+    lassert(1<=p, "1<=p");
+    lassert(2>=p, "2>=p");
+    if(resultv[act] > 0 && resultv[act] != p){
+        return false;
+    }
+    if(resultv[act] == p){
+        return true;
+    }
+    resultv[act] = p;
+    if(overlaps[act].sz == 0){
+        return true;
+    } else {
+        foreach(it, overlaps[act]){
+            bool r = recur(*it, 3-p);
+            if(!r){
+                return false;
+            }
+        }
+        return true;
+    }
 }
 
 // write to COMM_TYPE result
 void calcFunction() {
+    compute_overlaps();
+    llog(overlaps);
+    resultv.clear();
+    resultv = v(ll)(N, 0);
+    result.clear();
+    bool possible=true;
+    while(true){
+        ll unfilled = distance(resultv.bn, find(all(resultv), 0));
+        if(unfilled != resultv.sz){
+            llog("resultv", resultv);
+            possible &= recur(unfilled, 1);
+            llog("resultv", resultv);
+            if(!possible){
+                break;
+            }
+        } else {
+            break;
+        }
+    }
+    if(possible){
+        foreach(p, resultv){
+            if(*p==1){
+                result += "C";
+            } else{
+                lassert(*p==2,"p==2");
+                result += "J";
+            }
+        }
+    }
+
 }
 
 } // namespace task
