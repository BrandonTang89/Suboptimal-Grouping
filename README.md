# Suboptimal-Grouping
A greedy algorithm for grouping people during social events for higher overall comfort.

<h3>About (Function)</h3>
Social gatherings usually have guests are divided into groups of X people (such as for sitting around a table). However, many organisers fail to accomplish this task logically and instead ask the guests to divide amongst themselves, assuming that this arrangement would be optimsal. However, such an arrangement makes it awkward for people with little friends/connetions to find a comfortable position and is geneally just a pain for people to go through.<br>

As such, <b>this algorithm aims to divide N people into groups of at most X people such that the overall comfort level is the relatively high while ensuring that the program runs in a reasonable amount of time.</b>
<br><br>
This algorithm has a time complexity of O(N^2) and a space complexity of O(N^2).<br>
Where N is the number of guests. <br>
Thus it is suitable for <b>N < 10000.</b> <br>

<h3>Installation and Usage</h3>
<i>Python 3.7+ is required if intending to run on linux</i><br>
Files required:
<ol>
  <li>human_in.txt</li>
  <li>main_linux.py for linux OR main_windows.exe for windows</li>
  <li>seating_arrangement_2 for linux OR seating_arrangement_2.exe for windows</li>
</ol>

<h4>Input Format</h4>
<ol>
  <li>The first line contains 2 integars, "the total number of guests [n]" and "the number of guest per group [x]"</li>
  <li>The next n lines start with a "the name of the guest in question [u]"</li>
  <li>The next word in the line is "the number of friends u has [e]"</li>
  <li>The next 2*e words are "the name of the friend [v]" and "the comfort level of u --> v [r]" (integar value only)</li>
</ol>

Output comes out as "human_out.txt"<br>

Summary:
<pre>
n x
u e {v r}*e //n times
</pre>
Example:
<pre>
8 3
bethany_chong_yu_lin 2 boey_sze_min_jeanelle 3 cheong_chi_yun_estene 1
boey_sze_min_jeanelle 1 bethany_chong_yu_lin 1
cheah_hoe_teng 3 chua_ren_kai 1 goh_yu_xiang_ranier 1 huang_kai_yao 1
cheong_chi_yun_estene 2 elena_goh_ching_ping 1 goh_yu_xiang_ranier 1
chua_ren_kai 3 cheah_hoe_teng 2 goh_yu_xiang_ranier 2 huang_kai_yao 2
elena_goh_ching_ping 0
goh_yu_xiang_ranier 3 chua_ren_kai 1 huang_kai_yao 1 cheong_chi_yun_estene 1
huang_kai_yao 3 goh_yu_xiang_ranier 1 chua_ren_kai 1 cheah_hoe_teng 1
</pre>
  
<h4>Collecting the data</h4>
Data for this can be collected through a simple survey.<br>
E.g.
<pre>https://docs.google.com/forms/d/e/1FAIpQLSf4oH4CtIbe3vVPAGfDO4xeAFMzXXen8OvSN6lIEeLMYj5WDg/viewform</pre>

The survey results are then formatted into a spreadsheet and can be copy pasted into the input file

<h4>Running the program</h4>
<ol>
  <li>Format input as stated above into "human_in.txt"</li>
  <li>Run main_linux.py for linux or "main_windows.exe" for windows</li>
</ol>
Notes:<br>
<ul>
  <li><b> !!IMPT!! Ensure there are exactly n+1 lines (i.e. get data on everyone)</b></li>
  <li><b>All names are one word only and cannot be numbers!! </b></li>
  <li>In linux, you need to make seating_arrangement_2 executable first using "chmod +x seating_arrangement_2"</li>
</ul>

<h3>Mechanism (Technical)</h3>
<ul>
  <li>Guests are modelled as vertices and friendships/connections are modelled as edges in a directional weighted graph</li>
  <li>Groups of people are modelled as subgraphs</li>
  <li>Each guest [g] gives a rating [R<sub>i</sub>] to the each other guest [i]</li>
  <li>The sum of weights edges away from each vertex is 1</li>
  <li>Thus the weight of each edge [g --> i] is 
  <img src="https://latex.codecogs.com/svg.latex?\dpi{300}&space;\large&space;\frac{R_{i}}{\sum&space;R_{i}}" title="\large \frac{R_{i}}{\sum R_{i}}" /></li>
  <li>The graph is converted from a directional to bidirectional graph by adding w(u --> v) and w(v --> u).</li>
  <li>Edges are greedily picked and nodes are grouped together through the use of the union find disjoint set data structure.</li>
  <li>If 2 groups are to be joined together to form a group with greater than x nodes, the group is not formed</li>
</ul>
