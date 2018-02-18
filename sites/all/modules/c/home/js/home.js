(function($) {

  var words = [];
  var current_word_index = 1;
  var current_pos = -1;
  var wordInfo = {
    'word': '',
    'pos': []
  };

  // Display a new word
  function init_show_word() {
    var theWord = wordInfo.word;
    var ix = 0;
    var pos = Math.floor((Math.random() * theWord.length));
    var html = '';
    var isFirstEmpty = false;
    for (ix=0; ix<theWord.length; ++ix) {
      html += '<span class="letter' + (!isFirstEmpty && pos!=ix ? ' blink' : '') + ' data-letter="">';
      html += pos == ix ? theWord[ix] : '_';
      html += ' </span>';
      console.log(ix);
      if (!isFirstEmpty && pos != ix) {
        isFirstEmpty = true;
        current_pos = ix;
      }
    }

    $('.word-line-wrap').empty().append(html);


    console.log(theWord);
    console.log(pos);
  }

  Drupal.behaviors.muread_home = {
    attach: function(context, settings) {

      words = settings.word_info.words;
      console.log(words);

      wordInfo.word = words[0]['word'];
      init_show_word();


      $('.keyboard-wrap .letter').on('click', function(e) {
        var clickedLetter = $(this).data('letter');
        var blinking_word = $('.word-line-wrap span').eq(current_pos);
        blinking_word.empty().append(' ' + clickedLetter);
        blinking_word.removeClass('blink');

        if (current_pos < wordInfo.word.length) {
          current_pos++;
          $('.word-line-wrap span').eq(current_pos).addClass('blink');
        }
        else {
          alert('end');
        }

      });

      $('.speak').on('click', function(e) {
        var text = new SpeechSynthesisUtterance(wordInfo.word);
        window.speechSynthesis.speak(text);
      });

      // Record hits
    /*
      $('.goto_origin').on('click', function() {
        var nid = $(this).data('nid');
        $.post('hit', {nid:nid}, function(result) {
        });
      });
      */

    }
  };

})(jQuery);
