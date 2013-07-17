<form action="#" class="node-question-form">
	<div class="form-item">
		<label for="question-title">标题</label>
		<input type="text" class="form-text" name="question-title" id="question-title" />
	</div>
	<div class="form-item">
		<label for="subject">选择科目</label>
		<select name="subject" id="subject" class="form-select">
			<option value="">----电脑与咨询科技----</option>
		</select>
	</div>
	<div class="form-item form-textarea-wrap">
		<label for="answer">我来回答</label>
		<div class="input">这里放文本编辑器</div>
	</div>
	<div class="group-more">
		<h3 class="title"><a href="#">更多</a></h3>
		<div class="group-more-wrapper">
			<div class="question-values">
				<table>
					<thead>
						<tr>
							<th colspan="2">附件</th>
						</tr>
					</thead>
					<tbody>
						<tr>
							<td><a href="#" class="tabledrage-handle"><div class="handle">&nbsp;</div></a></td>
							<td>
								<div class="media-widget">
									<a href="#" class="btn">Select media</a>
									<a href="#" class="btn">remove media</a>
								</div>
							</td>
						</tr>
					</tbody>
				</table>
			</div>
			<div class="add-tags"><input type="submit" class="btn" value="Add another item"></div>
			<div class="form-item">
				<label for="addtags">标签</label>
				<input type="text" class="form-text" name="addtags" id="addtags" />
			</div>
		</div>
	</div>
	<div class="form-actions">
		<button class="btn" type="submit">提问</button>
	</div>
</form>