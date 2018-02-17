
    <div class="items-container text-center">

      <div class="row word-line-label">
            Complete the word below
      </div>

      <div class="row word-line-wrap">
        <?php foreach ($letters as $key => $letter): ?>
          <?php if ($key == 0): ?>
          <span class="ix0"> &#9608</span>
          <? else: ?>
          <span class="ix<?php print $key; ?>"> <?php print $letter['status'] == 0 ? '_' : $letter['letter']; ?></span>
          <? endif; ?>
        <?php endforeach; ?>
      </div>

    </div>


