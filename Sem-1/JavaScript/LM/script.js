const output = document.getElementById("output");

    function showProfile() {
      output.innerHTML = `
        <h4>Student Profile</h4>
        <p><b>Name:</b> Vishal</p>
        <p><b>Roll No:</b> 12345</p>
        <p><b>Course:</b> MCA</p>
        <p><b>Email:</b> vishal@123gmail.com</p>
      `;
    }

    function showCategory() {
      output.innerHTML = `
        <h4>Books Category</h4>
        <ul class="list-unstyled">
          <li><i class="bi bi-bookmark"></i> Science</li>
          <li><i class="bi bi-bookmark"></i> Technology</li>
          <li><i class="bi bi-bookmark"></i> C</li>
          <li><i class="bi bi-bookmark"></i> History</li>
        </ul>
      `;
    }

    function showIssue() {
      let today = new Date();
      output.innerHTML = `
        <h4>Issue Section</h4>
        <p>Today's Date: <b>${today.toDateString()}</b></p>
      `;
    }

    function showReturn() {
      output.innerHTML = `
        <h4>Return Section</h4>
        <p>Please return your books within <b>15 days</b> of issue.</p>
      `;
    }

    function showReading() {
      let today = new Date();
      let day = today.getDay();
      if (day === 0) {
        output.innerHTML = `<h4>Reading Section</h4><p><b>It's closed today</b></p>`;
      } else {
        output.innerHTML = `<h4>Reading Section</h4><p>Working hour time is <b>9:00 am to 6:00 pm</b></p>`;
      }
    }

    // js creating button
    let btn = document.createElement("button");
    btn.innerText = "Happy to be volunteer";
    btn.className = "btn btn-success mt-3";
    btn.onclick = function () {
      let newWin = window.open("", "_blank");
      let today = new Date();
      newWin.document.write(`
        <h2 style="text-align:center;">Welcome to the library Family</h2>
        <p style="text-align:center;">Today's Date: <b>${today.toDateString()}</b></p>
      `);
    };
    document.body.append(btn);