
    <div class="items-container text-center">

      <div class="row word-line-label">
            Complete the word below
      </div>

      <div class="row word-line-wrap">
        <?php foreach ($letters as $letter): ?>
          <span> <?php print $letter['status'] == 0 ? '_' : $letter['letter']; ?></span>
        <?php endforeach; ?>
      </div>

    </div>


