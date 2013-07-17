<div class="form-item">
  <label for="username" class="icon icon-user ir">username</label>
  <input type="text" class="form-text" id="username" name="name" required placeholder="WEB-Design">
</div>
<div class="form-item">
  <label for="password" class="icon icon-password ir">password</label>
  <input type="password" class="form-text" id="passowrd" name="pass" requied placeholder="******">
</div>
  <?php print drupal_render($form['form_build_id']); ?>
  <?php print drupal_render($form['form_id']); ?>
  <?php print drupal_render($form['actions']); ?>
<div class="form-item">
  <div class="get-psw">Forgot Password <?php print l('Click here', 'user/password'); ?></div>
</div>
