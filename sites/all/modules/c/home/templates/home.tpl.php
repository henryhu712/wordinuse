
    <div class="items-container text-center">

      <div class="row word-line-label">
            Complete the word below
      </div>

      <div class="row word-line-wrap">
        <?php foreach ($letters as $key => $letter): ?>
          <?php if ($key == 10): ?>
          <span class="ix0"> &#9608</span>
          <?php else: ?>
          <span class="ix<?php print $key; ?>"> <?php print $letter['status'] == 0 ? '_' : $letter['letter']; ?></span>
          <?php endif; ?>
        <?php endforeach; ?>
      </div>

    </div>

    <div class="keyboard-wrap">
      <div class="row">
        <button id="letter-q">Q</button>
        <button id="letter-w">W</button>
      </div>
      <div class="row">
        <button id="letter-a">A</button>
        <button id="letter-s">S</button>
      </div>
    </div>
