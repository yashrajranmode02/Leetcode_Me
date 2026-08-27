<h2><a href="https://www.geeksforgeeks.org/problems/reducing-walls4443/1">Min Decrement by K Operations to Limit Array</a></h2><h3>Difficulty Level : Difficulty: Basic</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">You are given an array&nbsp;<strong>arr[] </strong>and an integer <strong>k</strong>. In one operation you can choose any element of array and decrease its value by k. </span></p>
<p><span style="font-size: 18px;">Find the <strong>minimum </strong>number of operation such that all the elements in the array becomes less or equal to <strong>k</strong>.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> arr[] = [5, 3, 2, 6, 8] and k = 5
<strong>Output:</strong> 2
<strong>Explanation:</strong> <br>Elements 5, 3, and 2 are already less than or equal to 5.
Element 6 can be reduced by 5 in one operation to become 1.
Element 8 can be reduced by 5 in one operation to become 3.
Thus, a total of 2 operations are required.
</span></pre>
<pre><span style="font-size: 18px;"><strong>Input:</strong> arr[] = [2, 6, 4, 8, 1, 6] and k = 4 <strong>
Output:</strong> 3 <br><strong>Explanation: <br></strong></span><span style="font-size: 18.6667px;">Elements 2, 4, and 1 are already less than or equal to 4.
Each occurrence of 6 can be reduced by 4 in one operation to become 2, requiring 2 operations.
Element 8 can be reduced by 4 in one operation to become 4, requiring 1 operation.
Therefore, the minimum number of operations required is 3.</span></pre>
<p><span style="font-size: 18px;"><strong>Constraints :</strong><br>1 ≤ arr.size() ≤ 2*10<sup>4</sup><br>1 ≤ k ≤ 10<sup>5</sup><br>1 ≤ arr[i] ≤ 10<sup>5</sup></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;