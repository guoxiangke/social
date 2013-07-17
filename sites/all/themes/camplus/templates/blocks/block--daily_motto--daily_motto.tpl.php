<div class="block block-daily-quote">
  <?php if ($block->subject): ?>
    <h2 class="block-title"><?php print $block->subject; ?></h2>
  <?php endif;?>
  <div class="block-content">
    <?php print $content; ?>
  </div>
</div>
