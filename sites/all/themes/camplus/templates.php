<?php
/*
*doctype file: html.php
*header content: header.php
*footer content: footer.php
*user profile: user-profile.php
*ranking: ranking.php
*sent weibo:block-weibo.php
*weibo feed:weibo-feed.php
*comments: comments.php
*daily quote: daily-quote.php
*interest people:interest-people.php
*blog header: blog-header.php
*blog list: block-blog.php
* hot blog: block-hot-blog.php
*archive blog: block-blog-archive.php
*add new blog: add-new-blog.php
*tabs: tab.php
*node: node.php
*node blog header:node-blog-header.php
*node blog content: node-blog-body.php
*rate average:rate-average.php
*node comment:node-comments.php
*knowledge search:knowledge-search.php
*hot question:hot-question.php
*node question form:node-question-form.php
+==============================+
*page home:index.php
*page login: login.php
*page blog: page-blog.php
*node blog: node-blog.php
*page knowledge:page-knowledge.php
*/
?>

<?php include("html.php")?>
<body>
	<div class="wrapper">
		<?php include("header.php")?>
		<!-- end header content -->
		<div id="page">
			<div class="container clearfix">
				<div class="container-wrapper">
					<div class="container-inner">
						<div id="main-content" class="clearfix">
							<div class="content fl">
								Main contnet 
							</div>	 
							<!-- end main contnet -->
							<div class="sidebar fl" id="second-sidebar">
								Right sidebar content 
							</div>
							<!-- end second sidebar content -->
						</div>
						<!-- end main content -->
						<div id="first-sidebar" class="sidebar clearfix">
							left side bar
						</div>					
						<!-- end first-sidebar content -->
					</div>
				</div>				
			</div>
		</div>
		<!-- end page content -->
		<?php include("footer.php")?>
		<!-- end footer content -->
	</div>	
</body>
</html>