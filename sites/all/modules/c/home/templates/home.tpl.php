
        <div class="row items-container text-center">
            Complete the word： 
        <?php foreach ($letters as $letter): ?>
          <span> <?php print $letter['status'] == 0 ? '-' : $letter['letter']; ?></span>
        <?php endforeach; ?>

        </div>


