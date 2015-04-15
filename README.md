<h2>Pocket Tanks Project</h2>

<h4>Git repository setup</h4>
<ol>
	<li>In Git Bash, navigate to the solution directory</li>
	<li>Type:<br /><code>git clone https://github.com/michalplatek/pocketTanks.git</code></li>
</ol>

<h4>Visual Studio 2013 solution setup</h4>

<p>Set the solution files as follows:</p>
<ul>
		<li>PocketTanks.sln</li>
		<li>Debug/</li>
		<li>Pocket Tanks/</li>
		<li>
			<ul>
				<li>.git</li>
				<li>.gitignore</li>
				<li>Box2D/ (contains Box2D/, freeglut/, Documentation/ etc.)</li>
				<li>boost/ (contains code only, no docs)</li>
				<li>main.cpp</li>
				<li>... (other project files: .cpp, .h)</li>
			</ul>
		</li>
</ul>

<p>Set the project dependencies (Project > Properties > C/C++ > Additional Include Directories):</p>
<ul>
	<li>$(SolutionDir)PocketTanks\</li>
	<li>$(SolutionDir)PocketTanks\Box2D\</li>
</ul>

<p>After that, the #includes should look like this:</p>
<ul>
	<li>#include &lt;Box2D/Box2D.h&gt;</li>
	<li>#include &lt;boost/geometry.hpp&gt;</li>
</ul>